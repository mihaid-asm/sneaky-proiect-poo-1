# sneaky-proiect-poo-1
Sneaky: The Game (2023-2024)
Sneaky este un joc realizat de Duzi Mihai-Nicolae(grupa 152) in C++ folosind POO.
Scopul jocului este sa colectati un numar suficient de iteme fara a fi surprinsi de inamici(marcati cu litere mari diferite de P).
Atat jucatorul(marcat cu litera P), cat si monstrii/inamicii au un "Health", un "Damage" si un "Range".
Daca jucatorul intra in range-ul unui monstru, acesta pierde atata "Health" cat damage are inamicul.
Daca un monstru este in range-ul jucatorului, monstrul pierde atata "Health" cat damage are jucatorul.
Daca un monstru ajunge cu "Health"<=0, acesta dispare de pe harta, iar daca jucatorul ajunge la "Health"<=0 jocul este considerat pierdut.
Fiecare nivel are un target, fiind necesar ca jucatorul sa-l atinga pentru a castiga jocul, colectand itemele marcate cu cifre ale caror cifra reprezinta valoarea in puncte.
Jocul are 3 nivele, la inceputul programului jucatorul avand posibilitatea sa aleaga un nivel(de la 1 la 3).
