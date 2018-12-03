# Database stuff

### Sqlite3
Dockerfile:
```
FROM alpine:latest

RUN apk add --no-cache sqlite
COPY users.sqlite /tmp/users.sqlite
RUN sqlite3 /tmp/users.db < /tmp/users.sqlite

ENTRYPOINT [ "/bin/sh" ]
```
Create user table and insert a dummy admin user with the password `password` (md5 hash inserted into the table).
users.sqlite:
```
create table users (id INT(11), username VARCHAR(50) NOT NULL, email VARCHAR(50) NOT NULL, password VARCHAR(50) NOT NULL, PRIMARY KEY (id));

INSERT INTO users VALUES (0, "admin", "admin@tghack.no", "5f4dcc3b5aa765d61d8327deb882cf99");
```



### sqlite3 + Node.js
installation: `npm install sqlite3`

```javascript
const sqlite3 = require('sqlite3').verbose();

// open the database from file
let db = new sqlite3.Database('./db/users.db', (err) => {
  if (err) {
    console.error(err.message);
  }
  console.log('Connected to the database.');
});

// query stuff
db.serialize(() => {
  db.each(`SELECT * FROM users`, (err, row) => {
    if (err) {
      console.error(err.message);
    }
    console.log(row.id + "\t" + row.name);
  });
});

// close the database connection
db.close((err) => {
  if (err) {
    return console.error(err.message);
  }
  console.log('Close the database connection.');
}
```
 
### Resources
* [How and When to Use Sqlite](https://www.digitalocean.com/community/tutorials/how-and-when-to-use-sqlite)
* http://www.sqlitetutorial.net/sqlite-nodejs/connect/
