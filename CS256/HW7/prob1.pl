% relations of the monsters
monster(X) :- vampire(X).
monster(X) :- ghost(X).
monster(X) :- werewolf(X).
monster(X) :- hybrid(X).

undead(X) :- vampire(X).

alive(X) :- werewolf(X).

dead(X) :- ghost(X).

looksLike(X, human) :- vampire(X), ghost(X).
looksLike(X, wolf) :- werewolf(X).

thrivesOn(X, blood) :- vampire(X).
thrivesOn(X, flesh) :- werewolf(X).
thrivesOn(X, fear) :- ghost(X).

ghost(X) :- poltergeist(X).

vampire(X) :- hybrid(X).

werewolf(X) :- hybrid(X).

vampire(dracula).
vampire(edward_cullen).
ghost(caspar).
poltergeist(peeves).
werewolf(sam_uley).
hybrid(michael_corvin).

% queries
% dead(peeves).
% thrivesOn(michael_corvin, X).
% monster(caspar). <-?????
% looksLike(sam_uley, X).
% vampire(X).
% thrivesOn(X, Y).
% looksLike(X, human); thrivesOn(X, fear).
