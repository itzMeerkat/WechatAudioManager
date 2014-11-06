package main

import (
	"bufio"
	//"fmt"
	"os"
	//"strings"
)

func main() {
	f, err := os.Open("eng.txt")
	defer f.Close()
	if err != nil {
		panic("WTF")
	}
	of, err := os.Create("output.txt")
	defer of.Close()
	if err != nil {
		panic("WTF")
	}
	br := bufio.NewReader(f)
	writer := bufio.NewWriter(of)
	for {
		//每次读取一行
		line, err := br.ReadString('\n')

		if err == nil {
			//print(string([]byte(line[3:len(line)])))
			for i := 0; i < len(line); i++ {
				if string(line[i]) == " " {
					print("!")
					writer.Write([]byte(line[i+1 : len(line)]))
					writer.Flush()
					break
				}
			}
		} else {
			break
		}
	}
}
