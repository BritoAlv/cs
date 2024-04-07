package main

import (
	"reflect"
	"testing"
)

func Test_splitInWords(t *testing.T) {
	type args struct {
		text string
	}
	tests := []struct {
		name string
		args args
		want []string
	}{
		// TODO: Add test cases.
		{"Test 1", args{"Hello World"}, []string{"Hello", "World"}},
		{"Test 2", args{"Hello World, how are you?"}, []string{"Hello", "World", "how", "are", "you"}},
		{"Test 3", args{"Hello World, how are you? I am fine, thank you."}, []string{"Hello", "World", "how", "are", "you", "I", "am", "fine", "thank", "you"}},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := splitInWords(&tt.args.text); !reflect.DeepEqual(got, tt.want) {
				t.Errorf("splitInWords() = %v, want %v", got, tt.want)
			}
		})
	}
}

func TestCountOccurrences(t *testing.T) {
	type args struct {
		word string
		text *string
	}
	x1 := string("Hello World")
	x2 := string("Hello Hello")
	tests := []struct {
		name string
		args args
		want int
	}{
		{"Test 1", args{"Hello", &x1}, 1},
		{"Test 2", args{"Hello", &x2}, 2},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			if got := CountOccurrences(tt.args.word, tt.args.text); got != tt.want {
				t.Errorf("CountOccurrences() = %v, want %v", got, tt.want)
			}
		})
	}
}
