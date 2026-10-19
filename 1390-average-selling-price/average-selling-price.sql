SELECT p.product_id,
      IFNULL(ROUND(SUM(p.price * U.units) / NULLIF(SUM(U.units), 0), 2), 0) AS average_price
FROM Prices AS p, UnitsSold AS U
WHERE p.product_id = U.product_id
  AND p.start_date <= U.purchase_date
  AND p.end_date >= U.purchase_date
GROUP BY p.product_id

UNION

SELECT p.product_id, 0 AS average_price
FROM Prices AS p
WHERE p.product_id NOT IN (
    SELECT product_id FROM UnitsSold
)

ORDER BY product_id ASC;