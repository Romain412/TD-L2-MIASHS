
-- QUESTION 1 --

SELECT COUNT(*) FROM clients;
SELECT COUNT(*) FROM paiements WHERE Paiement LIKE 'NON';
SELECT SUM(Montant) FROM paiements WHERE Paiement LIKE 'NON';
SELECT MAX(Montant) FROM paiements WHERE Paiement LIKE 'NON';
SELECT COUNT(*) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client WHERE Nom LIKE 'Patrick' AND prenom LIKE 'LOTELIER';
SELECT COUNT(*) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client WHERE Paiement LIKE 'NON' AND Ville LIKE 'Lyon' AND YEAR(DateP)='2015';



-- QUESTION 2 --

SELECT Nom,Prenom,COUNT(*) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client  WHERE Paiement LIKE 'NON' GROUP BY Nom; 
SELECT YEAR(DateP),COUNT(*) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client  WHERE Paiement LIKE 'NON' GROUP BY YEAR(DateP) ORDER BY YEAR(DateP);
SELECT Nom,prenom,AVG(Montant) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client  WHERE Paiement LIKE 'NON' GROUP By Nom;
SELECT COUNT(*) FROM paiements INNER JOIN clients ON paiements.RefClient=clients.ID_Client WHERE Paiement LIKE 'NON' GROUP BY Nom,YEAR(Date_P);
