CREATE TABLE students (
    id SERIAL PRIMARY KEY,
    name TEXT,
    age INTEGER
);

INSERT INTO students (name, age)
VALUES ('Bat', 20);

SELECT * FROM students;

SELECT 1 + 1;

INSERT INTO students (name, age)
VALUES ('Bold', 'twenty');

INSERT INTO students (name, age)
VALUES ('Bold', 20);

SELECT * FROM students;