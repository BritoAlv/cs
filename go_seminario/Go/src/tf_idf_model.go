package main

import "math"

type ModelTfIdf struct {
	// create a map that will store the Idf values for each word.
	Idf            map[string]int
	Items          []ResultFromDto
	Keys           []string
	Tf             map[string]map[string]int
	TotalDocuments int
}

func ConstructormodelTfIdf(arr []ResultFromDto) (*ModelTfIdf, error)  {
	idf := make(map[string]int)
	td := make(map[string]map[string]int, len(arr))
	numberOfDocuments := len(arr)
	for _, doc := range arr {
		tfmap := make(map[string]int)
		wordsInDoc := splitInWords(doc.Text())
		for _, word := range wordsInDoc {
			// if the word is not in the idf map, add it.
			if _, ok := idf[word]; !ok {
				idf[word] = 1
			}
			if _, ok := tfmap[word]; !ok {
				tfmap[word] = 0
			}
			tfmap[word]++
		}
		td[doc.Name()] = tfmap
	}
	keys := Keys[string](idf)
	return &ModelTfIdf{idf, arr, keys, td, numberOfDocuments}, nil
}

func tdIdfCalculator(words []string, source map[string]int, model *ModelTfIdf) []float64{
	result := make([]float64, len(words))
	for index, word := range words {
		result[index] = 0
		if v, ok := source[word]; ok {
			result[index] += float64(v) * math.Log(float64(model.TotalDocuments)/float64(model.Idf[word]+1))
		}
	}
	return result
}

func QueryWords(wordsInDoc []string, model *ModelTfIdf) map[string]int {
	tfmap := make(map[string]int)
	for _, word := range wordsInDoc {
		if _, ok := tfmap[word]; !ok {
			tfmap[word] = 0
		}
		tfmap[word]++
	}
	return tfmap
}

func cos_sim(a []float64, b []float64) float64 {
	// calculate the cosine similarity between a and b.
	var dotProduct = float64(0)
	var magA = float64(0)
	var magB = float64(0)
	for i := 0; i < len(a); i++ {
		dotProduct += a[i] * b[i]
		magA += a[i] * a[i]
		magB += b[i] * b[i]
	}
	if magA == 0 || magB == 0 {
		return 0
	}
	return dotProduct / (math.Sqrt(magA) * math.Sqrt(magB))
}