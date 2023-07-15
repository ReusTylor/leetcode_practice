SELECT car,  COUNT(*) AS count
FROM test
GROUP BY car
HAVING COUNT(*) >= 2;