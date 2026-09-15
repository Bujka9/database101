
-- ADMIN USER

-- 1. Database үүсгэх
CREATE DATABASE school_db;

CREATE DATABASE finance_db;


-- 2. Student user / role үүсгэх
CREATE ROLE student_user
LOGIN
PASSWORD 'student123';

-- 3. school_db database-д холбогдох эрх өгөх
GRANT CONNECT ON DATABASE school_db TO student_user;

-- 4. public schema ашиглах эрх өгөх
GRANT USAGE ON SCHEMA public TO student_user;











-- user -ийг CREATE эрхгүйг тестлэсний дараа эрх өгөх
GRANT CREATE ON SCHEMA public TO student_user;





-- STUDENT USER
SELECT current_user;

CREATE TABLE test_table (
    id SERIAL PRIMARY KEY
);
-- ERROR: permission denied for schema public
--
-- student_user нь public schema дээр
-- USAGE эрхтэй боловч CREATE эрхгүй байна.


-- admin -аас CREATE эрх өгсөний дараа
CREATE TABLE test_table (
    id SERIAL PRIMARY KEY
);
SELECT * FROM test_table;











