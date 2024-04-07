package main

import (
	"log"
	"os"
	"path/filepath"
)

type ResultFromTxtDto struct {
	path string
}

func (r *ResultFromTxtDto) Name() string {
	return filepath.Base(r.path)
}

func (r *ResultFromTxtDto) Snippet() *string {
	maxLen := 200
	// read the first max_len characters from the file.
	// if the file is shorter than max_len, return the whole file.
	// if the file is empty, return an empty string.
	tt := r.Text()
	if len(*tt) < maxLen {
		return tt
	} else {
		sub := (*tt)[:maxLen]
		return &sub
	}
}

func (r *ResultFromTxtDto) Text() *string {
	file, err := os.Open(r.path)
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()
	buf := make([]byte, 100000)
	n, err := file.Read(buf)
	if err != nil {
		log.Fatal(err)
	}
	sub := string(buf[:n])
	return &sub 
}

func read_txt_files_local() []ResultFromTxtDto {
	files, err := os.ReadDir("./database/")
	if err != nil {
		log.Fatal(err)
	}
	items := make([]ResultFromTxtDto, 0)
	for _, file := range files {
		if filepath.Ext(file.Name()) == ".txt" {
			items = append(items, ResultFromTxtDto{"./database/" + file.Name()})
		}
	}
	return items
}
