package main

type ResultToWebDto interface {
	Name() string
	Snippet() *string
}

type ResultFromDto interface {
	ResultToWebDto
	Text() *string
}
