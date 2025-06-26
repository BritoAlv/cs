import datetime

DATE_FORMAT = '%Y-%m-%d %H:%M:%S'

class ContestResult:
    def __init__(self, contest_id, rank, points, contest_name, date_participated : str):
        self.contest_id : str = contest_id
        self.rank : int = rank
        self.points = points
        self.contest_name : str = contest_name
        self.date_participated = date_participated