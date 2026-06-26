# Write your MySQL query statement below
select distinct author_id AS id  from Views #'as id' IMPPP, output col is id
where author_id = viewer_id
Order BY id ASC;