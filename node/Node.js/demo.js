var mysql = require('mysql');

//connectiong to mysql
var con = mysql.createConnection({
    host:"localhost",
    user:"root",
    password: "Mcflonilo123",
    database: "mydb"
});
con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");

    var all ='*';
    var from = 'customers';

    var name = 'Amy';
    var adr = 'Mountain 21';
    var sql = 'SELECT * FROM customers WHERE name = ? OR address = ?';
    

  con.query(sql,[name,adr], function (err, result, fields) {
    if (err) throw err;
    console.log(result);
  });
});