var firstQuote=0;
var lastQuote=19;
var pageNo=1;
var flag=true;
document.addEventListener("DOMContentLoaded",
  function(){
     if(flag){
        english();
        flag=false;
     }
  })

//For english qoutes
function english(){
console.log("Hi");
       var req=new XMLHttpRequest();
       req.onreadystatechange=function(){
          if(this.readyState==4&&this.status==200){
            var res=JSON.parse(this.responseText);

            var sel=document.getElementById("quote");
            sel.innerHTML = null;

            for(var i=firstQuote;i<=lastQuote;i++){
               sel.innerHTML += "<div>"+res[i].text+"<div>"+res[i].author+"</div>"+"</div>";
            }
            var sel2=document.querySelector(".pageNo");
            sel2.textContent="Page : "+pageNo;             
          }

          var sel2 = document.getElementById("next1");
        sel2.style.display="block";
        
        var sel3 = document.getElementById("next2");
        sel3.style.display="block";

        var sel4 = document.getElementById("next3");
        sel4.style.display="block";
       }
       req.open("GET","https://type.fit/api/quotes",true);
       req.send(null);
}(window);

//For marathi quotes
function marathi(){
   var req=new XMLHttpRequest();
   req.onreadystatechange=function(){
      if(this.readyState==4&&this.status==200){
        var res=JSON.parse(this.responseText);
        var quotes=res.marathi;

        var sel=document.getElementById("quote");

        sel.innerHTML=null;
        
        for(var i=1;i<=quotes[0];i++){
           sel.innerHTML += "<div>"+JSON.stringify(quotes[i])+"</div>";
        }
        var sel2 = document.getElementById("next1");
        sel2.style.display="none";
        
        var sel3 = document.getElementById("next2");
        sel3.style.display="none";

        var sel4 = document.getElementById("next3");
        sel4.style.display="none";
      }
   }
   req.open("GET","./index.json",true);
   req.send(null);
}

/*** For next page of quotes****/
function next(){
   firstQuote+=20;
   lastQuote+=20;
   pageNo++;
   english();
}


function prev(){
   if(pageNo>1){
      firstQuote-=20;
      lastQuote-=20;
      pageNo--;
      english();
   }
}