const FruitShop = require("./fruitsShopClass")

const fruitShop = new FruitShop.FruitShop
const drinkMachine = new FruitShop.DrinkMachine

fruitShop.on("order", (fruits, size) => {
    console.log(` ${fruitShop.orderNumber} ${size} Order received, making you a ${size} fruit plate of fruits: ${fruits}`);
    drinkMachine.serveDrink(size);
});

fruitShop.order(['apples','pears','bananas'], 'full')
fruitShop.order(['kiwi','grapes','cherries'], "half")
fruitShop.getOrderNumber()