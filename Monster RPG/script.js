let xp = 0;
let health = 100;
let gold = 10;
let currentWeapon = 0;
let fighting;
let monsterHealth;
let inventory = ["stick"];

const button1 = document.querySelector("#button1");
const button2 = document.querySelector("#button2");
const button3 = document.querySelector("#button3");
const text = document.querySelector("#text");
const xpText = document.querySelector("#xpText");
const healthText = document.querySelector("#healthText");
const goldText = document.querySelector("#goldText");
const monsterStats = document.querySelector("#monsterStats");
const monsterNameText = document.querySelector("#monsterName");
const monsterHealthText = document.querySelector("#monsterHealth");

const weapons = [
    {
        name: "stick",
        power: 5
    },
    {
        name: "rock",
        power: 15
    },
    {
        name: "dagger",
        power: 30
    },
    {
        name: "bow",
        power: 75
    },
    {
        name: "sword",
        power: 100
    }
];

const monsters = [
    {
        name: "orek",
        level: 3,
        health: 60
    },
    {
        name: "goblin",
        level: 2,
        health: 25
    },
    {
        name: "dragon",
        level: 20,
        health: 400
    }
]

const locations = [
    {
        name: "town square",
        "button text": ["Go to store", "Go to cave", "Fight dragon"],
        "button functions": [goStore, goCave, fightDragon],
        text: "You are in the town square. you see a sign that says \"store\"."
    },
    {
        name: "store",
        "button text": ["Buy 10 health (10 gold)", "Buy weapon (30 gold)", "Go to town square"],
        "button functions": [buyHealth, buyWeapon, goTown],
        text: "You enter the store."
    },
    {
        name: "cave",
        "button text": ["Fight orek", "Fight goblin", "Go to town square"],
        "button functions": [fightOrek, fightGoblin, goTown],
        text: "You enter the cave. Get ready to fight!"
    },
    {
        name: "items",
        "button text": ["Dagger (20 gold)", "Bow (35 gold)", "Sword (50 gold)"],
        "button functions": [() => weaponsToBuy(2), () => weaponsToBuy(3), () => weaponsToBuy(3)],
        text: "Pick an item."
    },
    {
        name: "fight",
        "button text": ["Attack", "Dodge", "Run"],
        "button functions": [attack, dodge, goTown],
        text: "You are fighting a " + monsters[fighting] + "."
    },
    {
        name: "kill monster",
        "button text": ["Go to town square", "Go to town square", "Go to town square"],
        "button functions": [goTown, goTown, goTown],
        text: "The enemy colapses to your might!"
    },
    {
        name: "lose",
        "button text": ["Restart", "Restart", "Restart"],
        "button functions": [restart, restart, restart],
        text: "You died...."
    },
    {
        name: "win",
        "button text": ["You WIN!!!", "Good JOB", "Play again?"],
        "button functions": [restart, restart, restart],
        text: "You defeat the dragon! You win the GAME !!!!"
    }
]

// Initialize buttons

button1.onclick = goStore;
button2.onclick = goCave;
button3.onclick = fightDragon;

// Call functions for buttons
function update(location) {
    monsterStats.style.display = "none";
    button1.innerText = location["button text"][0];
    button2.innerText = location["button text"][1];
    button3.innerText = location["button text"][2];
    button1.onclick = location["button functions"][0];
    button2.onclick = location["button functions"][1];
    button3.onclick = location["button functions"][2];
    text.innerText = location.text;
    goldText.innerText = gold;
    healthText.innerText = health;
}
function goTown() {
    update(locations[0])
}
function goStore() {
    update(locations[1])
}
function goCave() {
    update(locations[2])
}
function buyHealth() {
    if (gold >= 10) {
        gold -= 10;
        health += 10;
        goldText.innerText = gold;
        healthText.innerText = health;
    }
}
function buyWeapon() {
    update(locations[3])
}
function weaponsToBuy(item) {
    let purchase = item;
    goldText.innerText = gold;
    if (currentWeapon < weapons.length - 1) {
        if ((purchase == 2) && (gold >= 20)) {
            inventory.push("dagger");
            gold -= 20;
            goldText.innerText = gold;
            currentWeapon = 2;
            let newWeapon = weapons[currentWeapon].name;
            text.innerText = "You now have a " + newWeapon + ".";
        }
        if (purchase == 3 && gold >= 35) {
            inventory.push("bow");
            gold -= 35;
            goldText.innerText = gold;
            currentWeapon = 3;
            let newWeapon = weapons[currentWeapon].name;
            text.innerText = "You now have a " + newWeapon + ".";
        }
        if (purchase == 4 && gold >= 50) {
            inventory.push("sword");
            gold -= 50;
            goldText.innerText = gold;
            currentWeapon = 4;
            let newWeapon = weapons[currentWeapon].name;
            text.innerText = "You now have a " + newWeapon + ".";
        }
    }
    text.innerText += " In your inventory you have: " + inventory;
    setTimeout(() => {
        goStore()
    }, 2000);
}
function fightOrek() {
    fighting = 0;
    goFight();
}
function fightGoblin() {
    fighting = 1;
    goFight();
}
function fightDragon() {
    fighting = 2;
    goFight();
}
function goFight() {
    let monster = monsters[fighting];
    if (monster) {
        update(locations[4])
        monsterHealth = monsters[fighting].health;
        monsterStats.style.display = "block";
        monsterNameText.innerText = monsters[fighting].name;
        monsterHealthText.innerText = monsterHealth;
    } else {
        console.error("Error: Monster not defined")
    }
}
function attack() {
    let monster = monsters[fighting];
    if (monster) {
        text.innerText = "The " + monster.name + " attacks.";
        text.innerText += " You attack it with your " + weapons[currentWeapon].name + ".";
        if (isMonsterhit()) {
            health -= getMonsterAttackValue(monster.level);
        } else {
            text.innerText = " You missed."
        }
        let damageDelt = weapons[currentWeapon].power + Math.floor(Math.random() * xp) + 1;
        monsterHealth -= damageDelt;
        healthText.innerText = health;
        monsterHealthText.innerText = monsterHealth;
        if (health <= 0) {
            lose();
        } else if (monsterHealth <= 0) {
            fighting === 2 ? winGame() : defeatMonster();
        }
    } else {
        console.error("Error: Monster not defined.")
    }

    if (Math.random() <= .1 && inventory.length !== 1) {
        text.innerText += " Your " + inventory.pop() + " break.";
        currentWeapon--;
    }
}
function getMonsterAttackValue(level) {
    let hit = (level * 5) - (Math.floor(Math.random() * xp));
    console.log(hit);
    return hit;
}
function isMonsterhit() {
    return Math.random() > .2 || health < 20;
}
function dodge() {
    text.innerText = "You dodge the attack from " + monsters[fighting].name + ".";
}
function defeatMonster() {
    gold += Math.floor(monsters[fighting].level * 6.7)
    xp += monsters[fighting].level;
    goldText.innerText = gold;
    xpText.innerText = xp;
    update(locations[5])
}
function lose() {
    update(locations[6])
}
function winGame() {
    update(locations[7])
}
function restart() {
    xp = 0;
    health = 100;
    gold = 10;
    currentWeapon = 0;
    goldText.innerText = gold;
    healthText.innerText = health;
    xpText.innerText = xp;
    goTown()
}