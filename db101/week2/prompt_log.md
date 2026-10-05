# Prompt Log

## Prompt 1

PostgreSQL permission denied яагаад гардаг вэ?

### Ойлгосон хариу

Хэрэглэгч тухайн үйлдлийг хийх шаардлагатай эрхгүй үед
permission denied алдаа гардаг.

Жишээ нь public schema дээр CREATE эрхгүй хэрэглэгч table
үүсгэх гэж оролдвол:

ERROR: permission denied for schema public

гэсэн алдаа гарна.

## Prompt 2

Client-Server архитектур гэж юу вэ?

### Ойлгосон хариу

pgAdmin нь client, PostgreSQL нь server юм.

Client нь SQL command-ыг server рүү илгээдэг.
PostgreSQL server нь command-ыг боловсруулж, database дээр
үйлдэл хийгээд үр дүнг client рүү буцаадаг.

## Prompt 3

GRANT USAGE болон GRANT CREATE ямар ялгаатай вэ?

### Ойлгосон хариу

USAGE эрх нь schema-г ашиглах боломж өгнө.

CREATE эрх нь schema дотор table зэрэг object шинээр үүсгэх
боломж өгнө.

Тиймээс USAGE эрхтэй боловч CREATE эрхгүй хэрэглэгч table
үүсгэж чадахгүй.
