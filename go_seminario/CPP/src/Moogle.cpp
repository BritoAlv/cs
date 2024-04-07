#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <httpserver.hpp>
using namespace httpserver;
using namespace std;

vector<string> splitInWords(string &text)
{
    // provide better implementation.
    auto isletter = [](char c) { return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); };
    vector<string> words = vector<string>();
    for (int i = 0; i < text.size(); i++)
    {
        if (!isletter(text[i]))
        {
            continue;
        }
        int start = i;
        int end = i;
        if (isletter(text[i]))
        {
            while (end + 1 < text.size() && isletter(text[end + 1]))
            {
                end++;
            }
        }
        string w = "";
        for (int j = start; j <= end; j++)
        {
            w += text[j];
        }
        words.push_back(w);
        i = end;
    }
    return words;
}

class ResultToApiDto
{
  public:
    string Name;
    string Snippet;
};

class ResultFromDto : public ResultToApiDto
{
  public:
    string Text;
};

class ResultFromTxt : public ResultFromDto
{
  public:
    ResultFromTxt(string path)
    {
        std::string line;
        std::ifstream myfile(path); // replace with your file path
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                this->Text += line;
            }
            myfile.close();
        }
        this->Name = filesystem::path(path).filename();
        this->Snippet = this->Text.substr(0, min((int)this->Text.size(), 100));
    }
};

class ModelTfIdf
{
  public:
    map<string, int> Idf;
    vector<ResultFromDto> Items;
    map<string, map<string, int>> Tf;
    unsigned long long TotalDocuments;
    ModelTfIdf(vector<ResultFromDto> &arr)
    {
        map<string, int> Idf = *(new map<string, int>());
        map<string, map<string, int>> Tf = *(new map<string, map<string, int>>());
        this->TotalDocuments = arr.size();
        for (ResultFromDto &doc : arr)
        {
            map<string, int> tfmap = *(new map<string, int>());
            auto wordsInDoc = splitInWords((doc.Text));
            for (string &word : wordsInDoc)
            {
                if (Idf.find(word) == Idf.end())
                {
                    Idf[word] = 1;
                }
                if (tfmap.find(word) == tfmap.end())
                {
                    tfmap[word] = 0;
                }
                tfmap[word]++;
            }
            Tf[doc.Name] = tfmap;
        }
        this->Idf = Idf;
        this->Tf = Tf;
        this->Items = arr;
    }
};

vector<float> tdIdfCalculator(vector<string> &words, map<string, int> &source, ModelTfIdf *model)
{
    auto result = vector<float>(words.size(), 0);
    for (int index = 0; index < words.size(); index++)
    {
        auto word = words[index];
        auto v = source.find(word);
        if (v != source.end())
        {
            float v1 = (*v).second;
            v1 *= log((float)model->TotalDocuments / (float)model->Idf[word] + 1);
            result[index] = v1;
        }
    }
    return result;
}

map<string, int> QueryWords(vector<string> &wordsInDoc, ModelTfIdf &model)
{
    map<string, int> tfmap = *(new map<string, int>());
    for (auto &word : wordsInDoc)
    {
        if (tfmap.find(word) == tfmap.end())
        {
            tfmap[word] = 0;
        }
        tfmap[word]++;
    }
    return tfmap;
}

float cos_sim(vector<float> A, vector<float> B)
{
    float result = 0;
    float mag_A = 0;
    float mag_B = 0;
    for (int i = 0; i < A.size(); i++)
    {
        result += A[i] * B[i];
        mag_A += A[i] * A[i];
        mag_B += B[i] * B[i];
    }
    if (mag_A == 0 || mag_B == 0)
    {
        return 0;
    }
    return result / (sqrt(mag_A) * sqrt(mag_B));
}

vector<ResultFromDto> read_txt_files_local(const std::string &folderPath)
{
    vector<ResultFromDto> ans = vector<ResultFromDto>();
    for (const auto &entry : std::filesystem::directory_iterator(folderPath))
    {
        if (entry.path().extension() == ".txt")
        {
            ResultFromTxt file = *(new ResultFromTxt(entry.path()));
            ans.push_back(file);
        }
    }
    return ans;
}

vector<ResultToApiDto> startSearchFromQuery(string inputValue, ModelTfIdf &model)
{
    auto querywords = splitInWords(inputValue);
    auto querySource = QueryWords(querywords, model);
    auto queryTfIdf = tdIdfCalculator(querywords, querySource, &model);

    vector<pair<float, int>> docs_values;
    for (int i = 0; i < model.TotalDocuments; i++)
    {
        docs_values.push_back(
            {cos_sim(tdIdfCalculator(querywords, model.Tf[model.Items[i].Name], &model), queryTfIdf), i});
    }
    sort(docs_values.begin(), docs_values.end());
    vector<ResultToApiDto> ans;
    for (int i = model.TotalDocuments - 1; i >= 0; i--)
    {
        ans.push_back(model.Items[docs_values[i].second]);
    }
    return ans;
}

class hello_world_resource : public http_resource
{
  public:
    hello_world_resource(ModelTfIdf *model)
    {
        this->model = model;
    }
    ModelTfIdf *model;
    shared_ptr<http_response> render_GET(const http_request &req)
    {
        string_view datapar = req.get_arg("query");
        if (datapar == "")
        {
            return shared_ptr<http_response>(new string_response("Waiting For A Query", 200));
        }
        else
        {
            vector<ResultToApiDto> to_show = startSearchFromQuery(string(datapar), *model);
            string result = "";
            for (auto &x : to_show)
            {
                result += x.Name;
                result += '\n';
                result += x.Snippet;
                result += '\n';
            }
            return shared_ptr<http_response>(new string_response(result, 200));
        }
    }
};

int main()
{
    auto items = read_txt_files_local("./database");
    ModelTfIdf *model = new ModelTfIdf(items);
    webserver ws = create_webserver(8080);
    hello_world_resource hwr = *(new hello_world_resource(model));
    ws.register_resource("/", &hwr, true);
    ws.start(true);
    return 0;
}