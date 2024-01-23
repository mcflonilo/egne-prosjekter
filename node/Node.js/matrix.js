const canvas = document.getElementById('Matrix');
const ctx = canvas.getContext('2d');
canvas.width = window.innerWidth;
canvas.height = window.innerHeight;
var hastranslated = false;
var fontsize = 25;
var middleresult = "";
var bintodecresult = "";
var bintohexresult = "";
var hextodecresult = "";
var hextobinresult = "";
var dectohexresult = "";
var dectobinresult = "";
var resultlength = middleresult.length;
var columnstart = 0;
var columnmiddle = Math.floor(canvas.width/fontsize/2);
var columnend = 0;
var rows = canvas.height/fontsize;

function setColumns(){
 	resultlength = middleresult.length;
    columnstart = 0;
	columnmiddle = Math.floor(canvas.width/fontsize/2);
 	columnend = columnmiddle + Math.floor(resultlength/2);}
		
class symbol {
	constructor(x, y, fontsize, canvasHeight){
		this.characters = 'アァカサタナハマヤャラワガザダバパイィキシチニヒミリヰギジヂビピウゥクスツヌフムユュルグズブヅプエェケセテネヘメレヱゲゼデベペオォコソトホモヨョロヲゴゾドボポヴッン0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ♔♕♖♗♘♙CHESS♚♛♜♝♞♟☀☁❆WEATHER❅❄♪MUSIC♫';
		this.x = x;
		this.y = y;
		this.fontSize = fontsize;
		this.text = '';
		this.canvasHeight = canvasHeight;
		
	}
	draw(context){
		this.text = this.characters.charAt(Math.floor(Math.random()*this.characters.length));
		setColumns();
		//executes after translation
		if (hastranslated==true){
		
		

		if(resultlength % 2 != 0) {
			columnstart = (columnmiddle - Math.floor(resultlength/2))-1;
		} else {
			columnstart = columnmiddle - Math.floor(resultlength/2);
		}
		
		var int = 0;
		if (this.x >= columnstart && this.x < columnend){
			int = 1;
		} else {
			int = 0;
		}
		switch (int) {
			case 1:
				if(this.y == (Math.floor(this.canvasHeight/this.fontSize/2))){
					this.text = middleresult.charAt((this.x-columnstart));
					ctx.fillStyle = 'rgba(255,0,0,1)';
					context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
					this.y += 1;
				} 
				else if (this.y > this.canvasHeight/this.fontSize && Math.random() > 0.95){
					this.y = 0;
				}
				else{
					ctx.fillStyle = 'rgba(0,255,0,1)';
					context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
					this.y += 1;
				}
			  break;
			case 0:
				if(this.y * this.fontSize > this.canvasHeight && Math.random() > 0.95){
					ctx.fillStyle = 'rgba(0,255,0,1)';
					context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
					this.y = 0;}
				
				else{
					ctx.fillStyle = 'rgba(0,255,0,1)';
					context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
					this.y += 1;}

		  }
		}

		// executes if nothing has been translated yet
		else {
			if(this.y * this.fontSize > this.canvasHeight && Math.random() > 0.95){
				ctx.fillStyle = 'rgba(0,0,255,1)';
				context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
				this.y = 0;
					
					
			} else{
				ctx.fillStyle = 'rgba(0,255,0,1)';
				context.fillText(this.text, this.x * this.fontSize, this.y * this.fontSize);
				this.y += 1;}
		}
	}
}

class Effect {
	constructor(canvasWidth, canvasHeight){
		this.canvasWidth = canvasWidth;
		this.canvasHeight = canvasHeight;
		this.fontSize = 25;
		this.columns = this.canvasWidth/this.fontSize;
		this.symbols = [];
		this.#initialize();
		
	}
	#initialize(){
		for (let i = 0; i < this.columns; i++){
		this.symbols[i] = new symbol(i, 0, this.fontSize, this.canvasHeight);
	}
		
	}
	resize(width,height){
		this.canvasHeight = height;
		this.canvasWidth = width;
		this.columns = this.canvasWidth/this.fontSize;
		this.symbols = [];
		this.#initialize();
	}
}


const effect = new Effect(canvas.width, canvas.height);
let lasttime = 0;
const fps = 30;
const nextframe = 1000/fps;
let timer = 0;

function animate(timestamp){
	const deltatime = timestamp - lasttime;
	lasttime = timestamp;
	
	if (timer > nextframe){
	ctx.fillStyle = 'rgba(0,0,0,0.05)';
	ctx.textAlign = 'center';

	/*if (hastranslated==true){
		ctx.fillRect(0, 0, canvas.width, (canvas.height/2)-(fontsize+fontsize/2));
		ctx.fillRect(0, (canvas.height/2), canvas.width, canvas.height);
		ctx.fillRect(0, 0, columnstart*fontsize-fontsize/2, canvas.height);
		ctx.fillRect(((columnend-1)*fontsize)+fontsize/2, 0, canvas.width, canvas.height);

		ctx.fillStyle = 'rgba(0,0,0,0.001)';
		ctx.fillRect(columnstart*fontsize-fontsize/2,canvas.height/2-fontsize, resultlength*fontsize, fontsize);

	}else{}*/
	ctx.fillRect(0, 0, canvas.width, canvas.height);


	ctx.font = effect.fontSize + 'px monospace';
	effect.symbols.forEach(symbol => symbol.draw(ctx));
	timer = 0;
}   else{
	timer += deltatime;
}

	requestAnimationFrame(animate);
}
animate(0);

window.addEventListener('resize', function(){
	canvas.width = window.innerWidth;
	canvas.height=window.innerHeight;
	effect.resize;
});


    function makestring(value){
		middleresult += value;
        }
    
    function Translatedectobin(){
    dectobinresult="";
	middleresult="";
    var binary = [];
    var number = document.getElementById("dectobininput").value;
    var quotient;
    var remainder; 
	var DTBresult = document.getElementById("DTBresult");
    for (;number >= 1;){
     quotient = Math.floor(number/2);
     remainder = number % 2;
     number= Math.floor(number/2);

        if(remainder == 1){
            binary.push("1")
        }
        else {
        binary.push("0")
        }
        }
        binary.reverse();
        binary.forEach(makestring);
        binary = [];
		hastranslated=true;
		DTBresult.innerHTML = dectobinresult;
    }
	function Translatebintodec(){
		bintodecresult="";
		var number = document.getElementById("bintodecinput").value;
		var numtext = number.toString();
		var sum=0;
		var BTDresult = document.getElementById("BTDresult");
		console.log("numtext length"+numtext.length)
		for (var i=0;i <= numtext.length+1;i++){
		 if(numtext.charAt(i)== "1"){
			sum += Math.pow(2,(numtext.length-1-i))
			console.log( Math.pow(2,(numtext.length-1-i)))
		}else {
		}
			}
			bintodecresult = sum
			console.log( sum);
			hastranslated=true;
			BTDresult.innerHTML = bintodecresult;
		}
		function Translatehextodec(){
			hextodecresult="";
			var number = document.getElementById("hextodecinput").value;
			var numtext = number.toString();
			var sum=0;
			var BTDresult = document.getElementById("HTDresult");
			console.log("numtext length"+numtext.length)
			for (var i=0;i <= numtext.length+1;i++){
			 if(isNaN(parseInt(numtext.charAt(i)))!=true){

				sum += (Math.pow(16,(numtext.length-1-i))*parseInt(numtext.charAt(i)))
				console.log(sum)
			}
			else if(numtext.charAt(i)=="a") {
				sum += (Math.pow(16,(numtext.length-1-i))*10)
				console.log(sum)

			}
			else if(numtext.charAt(i)=="b") {
				sum += (Math.pow(16,(numtext.length-1-i))*11)
				console.log(sum)

			}
			else if(numtext.charAt(i)=="c") {
				sum += (Math.pow(16,(numtext.length-1-i))*12)
				console.log(sum)

			}
			else if(numtext.charAt(i)=="d") {
				sum += (Math.pow(16,(numtext.length-1-i))*13)
				console.log(sum)

			}
			else if(numtext.charAt(i)=="e") {
				sum += (Math.pow(16,(numtext.length-1-i))*14)
				console.log(sum)

			}
			else if(numtext.charAt(i)=="f") {
				sum += (Math.pow(16,(numtext.length-1-i))*15)
				console.log(sum)

			}
				}
				bintodecresult = sum
				console.log( sum);
				hastranslated=true;
				BTDresult.innerHTML = bintodecresult;
			}
			function Translatedectohex(){
				dectohexresult="";
				middleresult="";
				var binary = [];
				var number = document.getElementById("dectohexinput").value;
				var quotient;
				var remainder; 
				var DTHresult = document.getElementById("DTHresult");
				for (;number >= 1;){
				 quotient = Math.floor(number/16);
				 remainder = number % 16;
				 number= Math.floor(number/16);
					console.log(remainder)
					if(remainder<10){
						binary.push(remainder.toString())
					}
					else if(remainder==10) {
						binary.push("a")
					}
					else if(remainder==11) {
						binary.push("b")
					}
					else if(remainder==12) {
						binary.push("c")
					}
					else if(remainder==13) {
						binary.push("d")
					}
					else if(remainder==14) {
						binary.push("e")
					}
					else if(remainder==15) {
						binary.push("f")
					}
					}
					binary.reverse();
					binary.forEach(makestring);
					binary = [];
					dectohexresult = middleresult
					console.log("1002939128317948798348732465");
					hastranslated=true;
					DTHresult.innerHTML = dectohexresult;
				}