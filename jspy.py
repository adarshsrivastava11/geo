import PyV8
ctx = PyV8.JSContext()
ctx.enter()

js = """
function escramble_758(){
var a,b,c
a='+1 '
b='84-'
a+='425-'
b+='7450'
c='9'
document.write(a+c+b)
}
escramble_758()
"""

print ctx.eval(js.replace("document.write", "return "))


