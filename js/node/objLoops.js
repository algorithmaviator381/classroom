let obj = {name: "Aditya",
        age: 18,
        skills: ["Git", "Scikit-Learn", "XGboost", "C++", "Javascript", "RPA"]
}


//  Iterate inside an object (eg. Dictionaries)
//  in keyword
for(let key in obj){
    console.log(key,"\t: ",obj[key])
}

//  Iterate inside an list (eg. Array)
//  of keyword
// for(let i of obj['skills']){
    // console.log(i)
// }