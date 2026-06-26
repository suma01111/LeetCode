# SELF JOIN

select w1.id from Weather w1
JOIN Weather w2
on DATEDIFF(w1.recordDate, w2.recordDate) = 1 ##REMEMBERRRR
WHERE w1.temperature > w2.temperature;
