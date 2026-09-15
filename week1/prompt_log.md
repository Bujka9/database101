# Prompt Log

## Prompt 1

PostgreSQL дээр TEXT болон INTEGER data type ямар ялгаатай вэ?

### Хариулт

TEXT нь тэмдэгт мөр хадгалдаг бол INTEGER нь бүхэл тоо хадгална.
Жишээ нь age INTEGER column-д 'twenty' гэсэн text утга шууд оруулах боломжгүй.

## Prompt 2

INSERT хийхэд "invalid input syntax for type integer" алдаа яагаад гардаг вэ?

### Хариулт

INTEGER төрлийн баганад integer болгон хөрвүүлэх боломжгүй текст утга
оруулах үед энэ алдаа гарна. Жишээ нь 'twenty'-г INTEGER болгон
хөрвүүлэх боломжгүй.

Зөв хувилбар:

INSERT INTO students (name, age)
VALUES ('Bold', 20);
