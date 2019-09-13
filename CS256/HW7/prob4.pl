
% part A
access(X) :- weapon_access(X), key_access(X), crime_access(X).

% part B
weapon_access(X) :- whereabouts(X, thursday, havener).
weapon_access(X) :- whereabouts(X, wednesday, library).
weapon_access(X) :- whereabouts(X, wednesday, csbuilding).
weapon_access(X) :- whereabouts(X, thursday, csbuilding).

% part C
key_access(X) :- whereabouts(X, monday, library).
key_access(X) :- whereabouts(X, tuesday, havener).
key_access(davis).

% part D
crime_access(X) :- whereabouts(X, thursday, csbuilding).
crime_access(X) :- whereabouts(X, friday, csbuilding).

% part E
whereabouts(mentis, monday, library).
whereabouts(mentis, tuesday, library).
whereabouts(mentis, wednesday, havener).
whereabouts(mentis, thursday, library).
whereabouts(mentis, friday, csbuilding).

whereabouts(grayson, monday, havener).
whereabouts(grayson, tuesday, havener).
whereabouts(grayson, wednesday, havener).
whereabouts(grayson, thursday, library).
whereabouts(grayson, friday, csbuilding).

whereabouts(ercal, monday, csbuilding).
whereabouts(ercal, tuesday, havener).
whereabouts(ercal, wednesday, csbuilding).
whereabouts(ercal, thursday, csbuilding).
whereabouts(ercal, friday, csbuilding).

whereabouts(davis, monday, csbuilding).
whereabouts(davis, tuesday, havener).
whereabouts(davis, wednesday, havener).
whereabouts(davis, thursday, library).
whereabouts(davis, friday, csbuilding).

whereabouts(tauritz, monday, csbuilding).
whereabouts(tauritz, tuesday, csbuilding).
whereabouts(tauritz, wednesday, library).
whereabouts(tauritz, thursday, csbuilding).
whereabouts(tauritz, friday, csbuilding).

whereabouts(cheng, monday, csbuilding).
whereabouts(cheng, tuesday, havener).
whereabouts(cheng, wednesday, havener).
whereabouts(cheng, thursday, csbuilding).
whereabouts(cheng, friday, csbuilding).

whereabouts(price, monday, library).
whereabouts(price, tuesday, library).
whereabouts(price, wedensday, havener).
whereabouts(price, thursday, library).
whereabouts(price, friday, csbuilding).

whereabouts(lin, monday, csbuilding).
whereabouts(lin, tuesday, library).
whereabouts(lin, wednesday, library).
whereabouts(lin, thursday, library).
whereabouts(lin, friday, csbuilding).

% part F
victim(leopold).

motive(X) :- jealous(leopold, X).
motive(X) :- insane(X).
motive(X) :- poor(X).

% part G
insane(tauritz).
insane(lin).

% part H
poor(davis).
poor(price).
poor(mentis).
poor(lin).

% part I
jealous(X, Y) :- involved_with(X, Z), involved_with(Y, Z).

% part J
involved_with(X, Y) :- involved(X, Y), !.
involved_with(X, Y) :- involved(Y, X).

% part K
involved(leopold, price).
involved(price, grayson). 
invovled(leopold, mentis).
invovled(mentis, cheng).
invovled(cheng, ercal).
invovled(ercal, lin).
invovled(tauritz, lin).
invovled(tauritz, grayson).

% part L
murderer(X) :- motive(X), access(X).
