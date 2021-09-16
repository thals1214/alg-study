var count = 0;
var ex1func = function() {
    console.log(count);
    if (++count > 4) clearInterval(timer);
};
var timer = setInterval(ex1func, 300);
