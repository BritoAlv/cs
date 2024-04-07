package main

import (
	"net/http"
	"sort"
	"text/template"
)

var model ModelTfIdf

func formHandler(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		inputValue := r.FormValue("query")
		items := startSearchFromQuery(inputValue)
		tmpl, _ := template.ParseFiles("answer.html")
		tmpl.Execute(w, items)
	} else {
		http.ServeFile(w, r, "yourfile.html")
	}
}

func startSearchFromQuery(inputValue string) []ResultToWebDto {
	// passing a sort function here determines which method should be
	// better.
	/*
	Return the document with most ocurrences of the query as a single word, only works for queries with one word.
	*/
	/* sort.Slice(items, func(i, j int) bool {
		return Compare(inputValue, items[i], items[j]) > 0
	}) */
	querywords  := splitInWords(&inputValue)
	querySource := QueryWords(querywords, &model)
	queryTfIdf := tdIdfCalculator(querywords, querySource, &model) 
	sort.Slice(model.Items, func(i, j int) bool {
		result1 := cos_sim(
			tdIdfCalculator( querywords, model.Tf[model.Items[i].Name()], &model), queryTfIdf)
		result2 := cos_sim(
				tdIdfCalculator( querywords, model.Tf[model.Items[j].Name()], &model), queryTfIdf)  
		return result1 > result2
		})	
	return Map(model.Items, func(r ResultFromDto) ResultToWebDto {
		return r.(ResultToWebDto)
	})
}

func setup_model() error {
	txtItems := read_txt_files_local()
	items := make([]ResultFromDto, len(txtItems))
	for i, item := range txtItems {
		items[i] = &item
	}
	m, err := ConstructormodelTfIdf(items)
	model = *m
	return err
}

func main() {
	err := setup_model()
	if err != nil{
		panic("Model can't be created why ?")
	}
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		http.ServeFile(w, r, "principal.html")
	})
	http.HandleFunc("/send_query", formHandler)
	http.ListenAndServe(":8080", nil)
}