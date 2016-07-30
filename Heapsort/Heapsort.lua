#!/usr/bin/lua

local Heapsort = {}
-----------------------------------------------------------
	Heapsort.bubble_down = function(table, begin, last)
		local root = begin
		local swap = root
		local child = root * 2

		while child <= last do
			if table[swap] < table[child] then
				swap = child
			end
			if	child + 1 <= last and
					table[swap] < table[child + 1] then
				swap = child + 1
			end

			if swap == root then return end

			table[root], table[swap] = table[swap], table[root]
			root = swap
			child = root * 2
		end
	end
-----------------------------------------------------------
	Heapsort.heapify_max = function(table)
		local begin = math.floor(#table/2)

		while begin >= 1 do
			Heapsort.bubble_down(table, begin, #table)
			begin = begin - 1
		end
	end
-----------------------------------------------------------
	Heapsort.sort = function(table)
		local last = #table

		Heapsort.heapify_max(table)

		while last > 1 do
			table[1], table[last] = table[last], table[1]
			last = last - 1
			Heapsort.bubble_down(table, 1, last)
		end
	end
-----------------------------------------------------------
	Heapsort.verify = function(t)
		local prev = t[1];
		for i,v in ipairs(t) do
			if i > 0 then
				if prev > v then error("ERROR: Unsorted!") end
				prev = v
			end
		end
	end


local test = {}
math.randomseed(os.time())
for i = 1,16 do
	table.insert(test, math.random(0,100))
end

print(unpack(test))
Heapsort.sort(test)
print(unpack(test))
Heapsort.verify(test)



