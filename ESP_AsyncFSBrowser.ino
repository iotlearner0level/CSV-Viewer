<!DOCTYPE html>
<html lang="en">
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <title>JS FileReader</title>
  <script>
//  input = document.querySelector('input[type="file"]')

//  </script>
<style>
* {
  box-sizing: border-box;
}
html, body { height: 100%; }
div{
  height:100%;
 /* overflow:auto;*/
   resize: both;

}

#fileview {
  position:relative;
  max-height:100vw;

  width:100%;
  height:80%;
/*  overflow:auto;*/

}

caption {
  font-family:  sans-serif;
  padding: 20px;
  caption-side: top;
  color: #666;
  text-align: left;
  letter-spacing: 1px;
}

#graph{
  display:block;
}

/*div{
  overflow:scroll;
}*/


#fileview td, th {
  border: 1px solid #ddd;
  padding: 8px;
}

#fileview tr:nth-child(even){background-color: #f2f2f2;}

#fileview tr:hover {background-color: #ddd;}

#fileview th {
  padding-top: 12px;
  padding-bottom: 12px;
  text-align: left;
  background-color: #4CAF50;
  color: white;
}
table{
  max-height:40vw;
  max-width:65vw;
  position:relative;
  display:inline-block; 
  overflow:auto;
  height:70%;
}



body {
  font-family: Arial, Helvetica, sans-serif;
}

/* Style the header */
header {
  background-color: #666;
  padding: 30px;
  text-align: center;
  font-size: 35px;
  color: white;
}

/* Create two columns/boxes that floats next to each other */
nav {
  float: left;
  width: 30%;
  height: auto; /* only for demonstration, should be removed */
  background: #ccc;
  padding: 20px;
  resize: both;

}

/* Style the list inside the menu */
nav ul {
  list-style-type: none;
  padding: 0;
}

article {
  float: left;
  padding: 20px;
  width: 70%;
  background-color: #f1f1f1;
  height: 70%; /* only for demonstration, should be removed */
  resize: both;

}

/* Clear floats after the columns */
section:after {
  content: "";
  display: table;
  clear: both;
}

/* Style the footer */
footer {
  background-color: #777;
  padding: 10px;
  text-align: center;
  color: white;
}

/* Responsive layout - makes the two columns/boxes stack on top of each other instead of next to each other, on small screens */
@media (max-width: 600px) {
  nav, article {
    width: 100%;
    height: auto;
  }
}
.clearfix::after {
  content: "";
  clear: both;
  display: table;
}
</style>
</head>

<body onload="testurl()">
  <div class='container clearfix'>
<header>
          <div id='graph' class='header'>
          </div>
</header>
<section>
          <div class='wrapper clearfix'>

            <nav>
            <div id='filelist' class='sidebar'></div>
            </nav>
          <article>
            <div id='fileview' class='content clearfix'></div>
          </article>
          </div>
</section>
        <footer>
          <div class='footer'>
            <input type="file" />
          </div>
        </footer>

    </div>

    <script>
  function testurl(){
const urlParams = new URLSearchParams(window.location.search);
console.log(location.search)
console.log(urlParams.has('filename')); // true
console.log(urlParams.get('product')); // "shirt"
urlfilename=urlParams.get('filename');
console.log(urlfilename);

var jsonFile = new XMLHttpRequest();
    jsonFile.open("GET",urlfilename,true);
    jsonFile.send();

    jsonFile.onreadystatechange = function() {
        if (jsonFile.readyState== 4 && jsonFile.status == 200) {
            document.getElementById("fileview").innerHTML = jsonFile.responseText;
  rawdata=jsonFile.responseText;


  var htmlstr="<table><caption>";
  htmlstr+=urlfilename;
  htmlstr+="</caption>"
  head=0;
//      console.log(reader.result)
  const lines = rawdata.split("\n").map(function(line){

    htmlstr+="<tr>"
    line.split(',').forEach(function separate(parts){
    if(head==0)
    htmlstr+="<th>"
    else htmlstr+="<td>"
    htmlstr+=parts;
    if(head==0){
    htmlstr+="</th>"

    }
    else htmlstr+="</td>"
//        console.log(`htmlstr=${htmlstr}`)
  })

    htmlstr+="</tr>"
    head=1

    return line.split(',')
  })
  htmlstr+="</table>"
  htmldiv=document.getElementById("fileview");
  htmldiv.innerHTML=htmlstr


//      console.log(lines)
  }

}

var dirFile = new XMLHttpRequest();
    dirFile.open("GET","list",true);
    dirFile.send();

    dirFile.onreadystatechange = function() {
        if (dirFile.readyState== 4 && dirFile.status == 200) {
            document.getElementById("filelist").innerHTML = dirFile.responseText;
            rawdata=jsonFile.responseText;
            console.log(rawdata)

}}

}
  const reader=new FileReader();

  input = document.querySelector('input[type="file"]')
  input.addEventListener('change',function(e){
    reader.onload=function (){
      var htmlstr="<table>";head=0;
//      console.log(reader.result)
      const lines = reader.result.split("\n").map(function(line){

        htmlstr+="<tr>"
        line.split(',').forEach(function separate(parts){
        if(head==0)
        htmlstr+="<th>"
        else htmlstr+="<td>"
        htmlstr+=parts;
        if(head==0){
        htmlstr+="</th>"

        }
        else htmlstr+="</td>"
//        console.log(`htmlstr=${htmlstr}`)
      })

        htmlstr+="</tr>"
        head=1

        return line.split(',')
      })
      htmlstr+="</table>"
      htmldiv=document.getElementById("fileview");
      htmldiv.innerHTML=htmlstr

//      console.log(lines)
    }
    reader.readAsText(input.files[0])
//    reader.readAsDataURL(input.files[0])

  },false)

  </script>

</body>
</html>
