{//inni her er alle de globale variablene
// alle html elementene
var lifebar = document.getElementById("life-bar")
var materialinfo = document.getElementById("material-info")
var buybuilding1btn = document.getElementById("buy-building-1-btn")
var buybuilding2btn = document.getElementById("buy-building-2-btn")
var buyswordbtn = document.getElementById("buy-sword-btn")
var buildingdiv = document.getElementById("building-div")
var monsterdiv = document.getElementById("monster-div")
var metalmine = document.getElementById("metal-mine")
var tree1 = document.getElementById("tree-1")
var tree2 = document.getElementById("tree-2")
var tree3 = document.getElementById("tree-3")
var outputdiv = document.getElementById("output-div")
var maindiv = document.getElementById("container")
//spillerliv
var playerhp = 300
//variabler til trærne
var wood = 0
var totalwood = 0
var woodgainedperclick = 25
var tree1health = 10
var tree2health = 10
var tree3health = 10;
//variabler til gruven
var metal = 0
var totalmetal = 0
var metalgainedperclick = 10
//vari9abler til bygningene
var building1woodcost = 50
var building1metalcost = 10
var building2woodcost = 150
var building2metalcost = 30
var bygninger = 0
var storbygg = 0
var småbygg = 0
//variabler til monstrene
var monsterdamage = 10
var enemyspawnrate = 10 //jo nærmere 1 jo mer usannsynlig
var numofmonsters = 0
var defaultmonsterhealth = 40
var defeatedenemies = 0
var maxenemies = 3
//variabler til sverd
var hassword = false
var styrke = 10
//variabler til text på siden
var maxtextmessages = 5
var textarray = []
}
//fiende klassen
class Enemy {
    /*valgte å lage en klasse til enemy siden det vil være lettere 
    å skalere opp hvis man plutselig hadde hatt lyst til å gjøre det*/
    constructor(m_health, m_id, attachTo) {
        this.health = m_health;
        this.id = m_id;
        this.progressbar = document.createElement("progress")
        this.progressbar.setAttribute("id", "progress"+m_id)
        this.progressbar.max = this.health
        this.progressbar.value = this.health
        this.div = document.createElement("div")
        this.div.setAttribute('id', "div"+m_id);
        this.div.style.display = "flex"
        this.div.style.flexDirection = "column"
        this.div.style.width = "100px"
        this.image = document.createElement("img");
        this.image.src = "images/cute-wolfman.png";
        this.div.appendChild(this.image);
        this.div.appendChild(this.progressbar);
        attachTo.appendChild(this.div);
        this.damage = function dmg(){
            this.health -= styrke
            if (this.health <= 0){
                this.div.remove()
                numofmonsters--
                defeatedenemies++}
            log("du angrep fiende og gjorde "+styrke+" skade")
            this.progressbar.value = this.health
        }
    } 
}
// funksjon for å bestemme hvor mange monstre som spawnes
function spawnwave(){
    //spawn wave bare finner ut hvor mange fiender som skal lages og kaller på spawnmonster så mange ganger
    var rng = Math.floor(Math.random() * 100)
    if(rng<=enemyspawnrate){
        var howmany = maxenemies-numofmonsters-Math.floor(Math.random() * 3)
        for(var i = 0 ; i<howmany ; i++){spawnmonster()}}
}
// funksjon for å spawne selve monsteret
function spawnmonster() {
    var spawn
    spawn = new Enemy(defaultmonsterhealth, numofmonsters, monsterdiv);
    //fant ingen god måte på å legge til event listener inne i selve klassen så legger til det her
    spawn.div.addEventListener("click", function(){spawn.damage()})
    numofmonsters++
}
//funksjon for når man går tom for liv
function gameover(){
    //sjekker om spilleren har gått tom for liv. hvis spilleren har det sletter den alt fra siden og lager en game over screen
    if(playerhp<=0){
        maindiv.remove()
        outputdiv.remove()
        endscreen = document.createElement("div")
        document.body.style.height = "100vh"
        document.body.style.display = "flex"
        document.body.style.justifyContent = "center"
        document.body.style.alignItems = "center"
        document.body.style.flexDirection = "column"
        document.body.appendChild(endscreen)
        endscreen.innerHTML = "<ul><h1>GAME OVER</h1><h2>STATS</h2><li> MONSTERKILLS : "+defeatedenemies+"</li><li> WOOD GATHERED: "+totalwood+"</li><li> METAL GATHERED: "+totalmetal+" </li><li> SMALL BUILDINGS: "+småbygg+"</li><li> BIG BUILDINGS: "+storbygg+" </li><li> STRENGTH: "+styrke+"</li></ul>"
        var restartbutton = document.createElement("button")
        restartbutton.innerHTML = "restart?"
        restartbutton.addEventListener("click", function(){
            window.location.reload()
        })
        document.body.appendChild(restartbutton)
    }
}
//endrer css på siden så koden min virker ordentlig
function altercss(){
    // dette er for å justere sånn at fiendene ikke spawner oppå hverandre men heller i en rad
    monsterdiv.style.display = "flex"
    monsterdiv.style.flexDirection = "row"
    monsterdiv.style.position = "absolute"
}
//oppdaterer informasjon om spillerliv og materialer
function updatemats() {
    //her oppdateres alle ressurs og liv verdier for spilleren
    var output = "Treverk:" + wood + " enheter. Metall: " + metal + " enheter. Antall bygninger: " + bygninger + ". Styrke: " + styrke + " "
    materialinfo.innerHTML = output
    lifebar.innerHTML = playerhp+"hp"
}
//printer ut de siste fem handlingene til spilleren
function log(text) {
    // valgte å bruke et array for å begrense hvor mange utskrifter som kunne vises om gangen.
    var string = ""
    textarray.unshift(text + "<br>")
    textarray.length = Math.min(textarray.length, maxtextmessages)
    for(var i = 0; i < textarray.length ; i++){
        string += textarray[i]
    }
    outputdiv.innerHTML = string
    string = ""
}
//skader spilleren
function skadspiller(){
    //skader spilleren. valgte å bare la den kalles av å grave i minen og å hogge trær siden fienden gjorde så mye skade
    if(numofmonsters>0){
        playerhp -= numofmonsters*monsterdamage
        gameover()
    }
}
//funksjon for å klikke på trærne
function getwood() {
    /* vurderte å lage en klasse for trærne også så man kunne enkelt lagt inn flere hvis man ville det 
    men var så mye styr med Enemy classen så valgte å ikke gjøre det*/
    if (this.id === "tree-1" && tree1health >= 1) {
        wood += woodgainedperclick
        tree1health--
        totalwood += woodgainedperclick
    }
    else if (this.id === "tree-2" && tree2health >= 1) {
        wood += woodgainedperclick
        tree2health--
        totalwood += woodgainedperclick
    }
    else if (this.id === "tree-3" && tree3health >= 1) {
        wood += woodgainedperclick
        tree3health--
        totalwood += woodgainedperclick
    }
    else {
        var removeelement = document.getElementById(this.id)
        removeelement.style.display = `none`;
    }
    updatemats()
    log("du hoggde tre og fikk 25 treverk")
    skadspiller()
    spawnwave()
}
//funksjon for å trykke på gruven
function getmetal() {
    metal += metalgainedperclick
    totalmetal += metalgainedperclick
    updatemats()
    log("du gravde i minen og fikk 10 metall")
    skadspiller()
    spawnwave()
}
//funksjon for å kjøpe sverd
function buysword() {
    if (metal >= 200 && hassword == false) {
        hassword = true
        styrke = 40
        metal = metal - 200
        updatemats()
        log("du kjøpte sverd og økte styrken din til 40")
        spawnwave()
    }else if(hassword == true){
        alert("du kan ikke ha mer enn ett sverd")
    }
}
//kjøpe liten bygning
function buybuilding1() {
    if (wood >= building1woodcost && metal >= building1metalcost) {
        wood -= building1woodcost
        metal -= building1metalcost
        buildingdiv.innerHTML += "<img src = images/building-1.png>"
        bygninger++
        småbygg++
        updatemats()
        log("du kjøpte en liten bygning")
        spawnwave()
    }
}
//kjøpe stor bygning
function buybuilding2() {
    if (wood >= building2woodcost && metal >= building2metalcost) {
        wood -= building2woodcost
        metal -= building2metalcost
        buildingdiv.innerHTML += "<img src = images/building-3.png>"
        bygninger++
        storbygg++
        updatemats()
        log("du kjøpte en stor bygning")
        spawnwave()
    }
}

altercss()
buyswordbtn.onclick = buysword
tree1.onclick = getwood
tree2.onclick = getwood
tree3.onclick = getwood
metalmine.onclick = getmetal
buybuilding1btn.onclick = buybuilding1
buybuilding2btn.onclick = buybuilding2