SELECT title from movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person_id = people.id
WHERE name IN ('Johnny Depp', 'Helena Bonham Carter')
GROUP BY title HAVING COUNT(title) = 2;y