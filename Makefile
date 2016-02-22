
all: typer

typer: typer.cc
	g++ -Wall -o typer typer.cc

clean:
	rm typer
