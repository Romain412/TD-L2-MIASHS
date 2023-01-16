


-- QUESTION 1 --


SELECT MAX(Remise) FROM détails_commandes;

SELECT SUM(Quantité) FROM détails_commandes INNER JOIN commandes ON détails_commandes.Réfcommande=commandes.N°commande 
INNER JOIN clients ON commandes.Refclient=clients.Codeclient WHERE clients.Société LIKE 'QUICK-Stop' AND YEAR(Date_commande)=2018;

SELECT SUM(PU*Quantité) FROM détails_commandes INNER JOIN commandes ON détails_commandes.Réfcommande=commandes.N°commande 
INNER JOIN clients ON commandes.Refclient=clients.Codeclient WHERE clients.Société LIKE 'Hanari Carnes';



--  QUESTION 2 --

SELECT Nom_catégorie, COUNT(*) AS nombre_produits FROM catégories INNER JOIN produits ON catégories.Code_catégorie=produits.Refcatégorie GROUP BY Nom_catégorie;
SELECT Pays,COUNT(*) AS nombre_clients FROM clients GROUP BY Pays;
SELECT Société, COUNT(N°commande) AS nombre_commandes FROM clients INNER JOIN commandes ON clients.Codeclient=commandes.Refclient GROUP BY Société;
SELECT Nom_catégorie,MIN(nombre_produits),MAX(nombre_produits),AVG(nombre_produits), COUNT(*) AS nombre_produits FROM catégories INNER JOIN produits ON catégories.Code_catégorie=produits.Refcatégorie GROUP BY Nom_catégorie;


-- QUESTION 3 --
SELECT  clients, Pays ,AVG(commandes.Frais_Port) FROM clients, commandes WHERE clients.Codeclient=commandes.Refclient HAVING AVG(commandes.Frais_Port)>500;
SELECT Codeclient, Société, SUM(PU*Quantité) AS Montant2019 FROM clients INNER JOIN commandes ON clients.Codeclient=commandes.Refclient 
INNER JOIN détails_commandes ON commandes.N°commande=détails_commandes.Réfcommande 
WHERE YEAR(Date_commande)=2019 Group BY Codeclient HAVING Montant2019>3000;

SELECT Codeclient, Société, COUNT(N°commande) AS CompteCommandes FROM clients INNER JOIN commandes ON clients.Codeclient=commandes.Refclient GROUP BY Codeclient 
HAVING Comptecommandes <5;

