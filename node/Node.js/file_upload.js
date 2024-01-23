var http = require('http');
var formidable = require('formidable');
var fs = require('fs');
var mysql =require('fs');

http.createServer(function (req, res) {
    if (req.url == '/fileupload') {
      var form = new formidable.IncomingForm();
      form.parse(req, function (err, fields, files) {
        var oldpath = files.filetoupload.filepath;
        var newpath = 'D:/Users/lmoph/Min disk/vscode_prosjekter/skole/uploaded_files/' + files.filetoupload.originalFilename;
        fs.copyFile(oldpath, newpath, function (err) {
          if (err) throw err;
          res.write('File uploaded and moved!');
          res.end();

          var name = files.filetoupload.originalFilename;
          var adr = 'D:/Users/lmoph/Min disk/vscode_prosjekter/skole/uploaded_files/';
          var sql = 'INSERT INTO customers (name, address) VALUES (?, ?)';
          
          con.query(sql,[name,adr], function (err, result, fields) {
            if (err) throw err;
            console.log(result);
          });
        });
   });
  
  }
    
    
    
    else {
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.write('<form action="fileupload" method="post" enctype="multipart/form-data">');
      res.write('<input type="file" name="filetoupload"><br>');
      res.write('<input type="submit">');
      res.write('</form>');
      return res.end();
    }
  }).listen(8080); 