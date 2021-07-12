%fatos
loves(romeo, juliet).
loves(juliet, romeo) :- loves(romeo, juliet).

:- dynamic(happy/2).

happy(albert).
happy(alice).
happy(bob).
happy(bill).
with_albert(alice).
with_albert(bob).

parent(albert,bob).
parent(albert,betsy).
parent(albert,bill).

parent(alice,bob).
parent(alice,betsy).
parent(alice,bill).

parent(bob,carl).
parent(bob,charlie).

runs(albert) :- 
    happy(albert).

dances(X) :-
    happy(X),
    with_albert(X).

does_dance(X) :- 
    dances(X),
    format('~w dances when It\'s happy and with Albert',[X]).

swims(X) :-
    happy(X).

is_even(X) :-
    Y is X//2, X =:= 2 * Y.

what_grade(5) :-
        write('You\'re pretty!'),nl,write('!').

related(X,Y) :-
    parent(X,Y).

related(X,Y) :-
    parent(X,Z),
    related(Z,Y).

show_name :-
    write('What is your name?'),nl,
    read(X),
    format('Hi ~w! Welcome to prolog',[X]).

write_to_file(File,Text):-
    open(File, write, Stream),
    write(Stream, Text),nl,
    close(Stream).
            
read_file(File) :-
    open(File, read, Stream),
    get_char(Stream, Char1),
    process_stream(Stream, Char1),
    close(Stream).

process_stream(_,end_of_file) :- !.

process_stream(Stream, Char) :-
    write(Char),
    get_char(Stream,Char2),
    process_stream(Stream, Char2).

guess_num :- loop(start).

loop(15) :- write('Acertou!!').

loop(X) :-
    \+ (X = 15),
    write('Adivinhe o número '),
    read(Guess),
    write(Guess),
    write(' is not the number'),nl,
    loop(Guess).
