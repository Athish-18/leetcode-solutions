console.log("athish");

//Reference types Objects , Arrays Functions

//Objects
let course = {
  title: "Python",
  description: "Prg Lang",
  rating: 5,
};
console.log(course);
console.log(course.title);
console.log(course["title"]);

// y val not changed bcz value type
let x = 3;
let y = x;
x = "ecp";
console.log(x);
console.log(y);

// p ,q val  changed bcz reference type ie object is reference type 
let p = { name: "ath" };
let q = p;
console.log(p.name);
console.log(q.name);

//Arrays
let courses = ["hld", "arr", "ath", 6, 5, null]; //b0th length and type can be dynamic
console.log(courses[0]);
console.log(courses[1]);
console.log(courses[2]);
console.log(typeof courses); // Arrays and functions  are also objects

//functions

CreateCourse("dsa"); //works even before creating fn
console.log(o); // logs undefined
var o = 3;
function CreateCourse(coursename) {
  console.log("creating " + coursename);
}
CreateCourse("python");
CreateCourse("C++");

//Execution Context
//1 memory phase - variable environment / var allocated memory
// 2. code phase -thread of execution line by line
// enabling a fn or var to access before initialisning  them is called hoisting

//this and window --same meaning
var h = 5;
console.log(h);
console.log(this.h);
console.log(window.h);

//let var const
//const and let are more strict than var
// const u cant reassign values then use let
// using let and const u cant access them without using it , but var is diff. But mem is allocated to all ie hoisting but u cant access because let and const are in temporal dead zone , but var is global scope.

// Block scope {}const and let block scope
// can access only var outside block not p and r

{
  let p = 8;
  const r = 7;
  var i = 8;
}
//lexical scope -- it checks if its available in the block if not then nearest var will be accessed ie for var. For let and const only inside we know

//More info on functions
function add(a, b) {
  return a + b;
}

console.log(add);
console.log(add(2, 3));

// Can be stored in a variable as well
var sum = function (a, b) {
  return a + b;
};

console.log(sum);
console.log(sum(5, 2));

//Passing fn as arguments in another fn
var sum = function (a, b) {
  return a + b;
};

var diff = function (a, b) {
  return a - b;
};

function operate(operationfn, a, b) {
  return operationfn(a, b);
}

console.log(operate(sum, 2, 3));
console.log(operate(diff, 5, 1));

// Higher order functions -- takes one or more fn as arguments or returns a function as its result

//Arrow Functions
var sum = (a, b) => {
  return a + b;
};
//OR
var sum = (a, b) => a + b; // bcz only one line

// FUnction inside another function
/*function outer()
{
  function inner()
  {
    console.log("hello");
  }
  return inner;
}

var retval=outer();
console.log(retval);
retval();
*/

//Function + Lexical scope
let v = 10;
function outer() {
  v = 100;
  function inner() {
    console.log(v);
  }
  return inner;
}

/*var retval = outer();
v = 80; // it is going to print 80 because it it has refence to a inside outer when called retval
console.log(retval);
retval();
*/


//Closure --fn with lexical scope --  ie increment counter has reference to fn as well as variable counter 
function outer()
{
  let count =0;
  function inner()
  {
    count++;
    console.log(count);
  }
  return inner;
}

let incrementCounter=outer(); // here inner is returned ie its not incremented ie count just reference to inner and count is made here 
incrementCounter();//1
incrementCounter();//2
incrementCounter();//3
incrementCounter();//4


//Closure leads to memory leaks -avoid 


// Async fns--
/*Here's what an async function is in simple (layman) language, in 3 lines:

An async function does things that take time, like downloading data from the internet.

It lets your program wait for that work to finish without freezing everything.

You can use await inside it to say, “wait here until this is done, then continue.”

if you don’t use await, then the code below will run immediately without waiting.

//Callbacks -- callback, which is a function passed to be called later (once the "data fetching" is done). To handle asynchronous functions.


/*function fetchdata(callback)
{
  setTimeout(()=>{
    console.log('fetched data');
  },5000); // After 5 sec its going to execute the console.log
}
*/

function fetchdata(callback) {
  setTimeout(() => {
    let data = "fetched data";
    callback(data,null);
  }, 5000); // After 5 sec its going to execute the console.log
} 


//the callback fn is handledata which is called after 5 sec
function handleData(data,error)
{
  if (error)
  {
    console.error(error);
  }
  else{
    console.log(data);
  }
}

fetchdata(handleData); // After 5 sec fetched data
//You're simulating an asynchronous operation (like fetching from a server).
/*After 5 seconds, the callback (handleData) is called with data. If there's an error, it would be passed too (but here it's null*/

//event queue and event loop -- when many set timer fns with callback fns are called so theres a big event queue not all the fns are called exactly after 5 sec 

//callback hell , pyramid of doom -- multiple async fn inside another nested

//Promises-- Objects that represents the state of async fns like completed / pending or not 

//3states -- pending , fulfilled , rejected 
function GetData(){
  return new Promise((resolve, reject) => {
    setTimeout(()=>{
      resolve('data fetched')// if reject("error") catch would execute rn result data fetched will execute 
    })
  })
}
// handling promise
GetData()
.then(result=>{
  console.log(result);
})
.catch(error=>{
  console.error(error);
})

//Another way to handle promise
async function GetData()
{
  try{
    const result=await GetData();
    console.log(result);
  }
  catch(error)
  {
    console.error(error);
  }
}

GetData();

//Common fns 
// 1.Map
const nums=[1,2,3,4];
console.log(nums);
const doubledNums=nums.map((nums)=>
  2*nums); //Doubled elements 
console.log(doubledNums);

//Filters
const numss = [1, 2, 3, 4];
console.log(numss);
const doubledNumss = numss.filter((numss) =>numss%2==0); //Filters all even nums
console.log(doubledNums);

//Reduce
const n = [1, 2, 3, 4];
console.log(n);
const sum = n.reduce((accumulator , n) => accumulator +n ); //FInds sum
console.log(doubledNums);



// Simple way to understand promises , async-await while fetching apis

const axios = require("axios");
const data = axios.get("https://cat-factt.herokuapp.com/facts"); //promise automatically created while fetching apis 
console.log(data); // logs promise pending bcz still not fetched yet

//promise -- if fetched prperly it will be stored in data and in data.then() can access it. If error in error u catch it 
const axios=require('axios');
const data=axios.get("https://cat-factt.herokuapp.com/facts");

data.then(()=>{
  console.log(res.data);
})
.catch(()=>{
  console.log(err)
})


//aysnc-await alt of promises
const axios = require("axios");
const fetchData= async()=>{
  try {
    const data=await axios.get("https://cat-factt.herokuapp.com/facts"); // if no await no use of async ie it wont stop exec it ll move forward ie pending u ll get.
    console.log(data);
  } 
  catch(err){
    console.log(err);
  }
}
fetchData();



