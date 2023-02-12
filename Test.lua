--dofile('lib1.lua')
require 'lib1'

co = coroutine.create(function ()
    for i=1,10 do
    print("co", i)
    coroutine.yield()
    end
end)

Array = { 'Lua', "Tutorial" }

for i = 1, 2 do
    print(Array[i])
end

print("Hello, foo")