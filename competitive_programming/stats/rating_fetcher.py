import requests
import os
import json

from common import ContestResult, DATE_FORMAT
from datetime import datetime

def get_contests_participated(codeforces_handle):
    # Step 1: Get submission history
    submissions_url = f"https://codeforces.com/api/user.status?handle={codeforces_handle}"
    submissions = requests.get(submissions_url).json()
    if submissions['status'] != 'OK':
        raise Exception("Error fetching submissions")
    
    # Step 2: Extract unique contest IDs
    contest_ids = {}
    for sub in submissions["result"]:
        if "contestId" in sub:
            contest_id = sub["contestId"]
            creation_date = sub["creationTimeSeconds"]
            date = datetime.utcfromtimestamp(creation_date)
            if contest_id in contest_ids:
                current_date = contest_ids[contest_id]
                contest_ids[contest_id] = min(current_date, date)
            else:
                contest_ids[contest_id] = date
    
    return contest_ids

def fetch_rank_in_contest(contest_id, date,  codeforces_handle, output_file):
    standings_url = f"https://codeforces.com/api/contest.standings?contestId={contest_id}&handles={codeforces_handle}&showUnofficial=true"
    resp = requests.get(standings_url).json()
    if resp["status"] != "OK":
        return None
    row = resp["result"]["rows"][0]
    rank = row.get("rank")
    object_to_json = ContestResult(contest_id, rank, row.get("points", 0), resp["result"]["contest"]["name"], date.strftime(DATE_FORMAT))
    data = object_to_json.__dict__

    # Load existing data
    if os.path.exists(output_file):
        with open(output_file, "r") as f:
            try:
                existing = json.load(f)
            except Exception:
                existing = {}
    else:
        existing = {}

    existing[str(contest_id)] = data

    with open(output_file, "w") as f:
        json.dump(existing, f, indent=2)

    return object_to_json

def fetch_all_standings(codeforces_handle, output_file_path):
    contest_ids = get_contests_participated(codeforces_handle)
    print(f"Found {len(contest_ids)} contests for user '{codeforces_handle}'")
    if not os.path.exists(output_file_path):
        with open(output_file_path, "w") as f:
            json.dump({}, f)
    
    # load into existing results.
    with open(output_file_path, "r") as f:
           raw_data = f.read()
           existing_results = json.loads(raw_data)

    for i, cid in enumerate(contest_ids):
        try:
            if str(cid) not in existing_results:
                result = fetch_rank_in_contest(cid, contest_ids[cid], codeforces_handle, output_file_path)
                if result:
                    existing_results[cid] = result
                    print(f"[{i+1}/{len(contest_ids)}] {result.contest_name} -> Rank: {result.rank}")
            
        except Exception as e:
            print(f"[{i+1}/{len(contest_ids)}] Contest {cid} failed: {e}")



handle = "BritoAlv"
fetch_all_standings(handle, f"{handle}_standings.json")
