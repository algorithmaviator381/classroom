const EventEmitter = require("node:events")

class FruitShop extends EventEmitter{
    constructor(){
        super();
        this.orderNumber = 0
    }

    order(fruits, size = "full") {
        this.orderNumber++;
        this.emit("order", fruits, size);
    }

    getOrderNumber(){
        console.log(`Current order: ${this.orderNumber}`)
    }

}

class DrinkMachine{
    serveDrink(size){
        if(size === 'full'){
            console.log("\tServing you a complimentary drink with full size")
        }else{
            console.log("\tNote: you can get a complimentary drink with a full fruit plate")
        }
    }
}

module.exports = {FruitShop,DrinkMachine}