//
//  File.swift
//  Algorithms
//
//  Created by Tiko on 5/31/23.
//

import Foundation

struct Vessel: Comparable {
    let index: Int
    var capacity: Int

    static func < (lhs: Vessel, rhs: Vessel) -> Bool {
        return lhs.capacity < rhs.capacity || (lhs.capacity == rhs.capacity && lhs.index < rhs.index)
    }
}

class VesselSolution {
    var vessels = [Vessel]()
    var waterInVessel = [Int: Int]()

    func addWater(to vesselIndex: Int, amount: Int) {
        var amount = amount
        while amount > 0 && !vessels.isEmpty {
            let smallestVessel = vessels.removeFirst()
            if smallestVessel.index >= vesselIndex {
                let pourAmount = min(amount, smallestVessel.capacity - (waterInVessel[smallestVessel.index] ?? 0))
                waterInVessel[smallestVessel.index, default: 0] += pourAmount
                amount -= pourAmount
                if waterInVessel[smallestVessel.index]! < smallestVessel.capacity {
                    vessels.insert(smallestVessel, at: 0)
                }
            }
        }
    }

    func solution() {
        let n = 3
        let capacities = [5, 10, 8]
        for (index, capacity) in capacities.enumerated() {
            vessels.append(Vessel(index: index + 1, capacity: capacity))
        }
        vessels.sort()

        let queries = [
            [1, 1, 12],
            [2, 2],
            [1, 1, 2],
            [2, 2]
        ]
        for query in queries {
            if query[0] == 1 {
                addWater(to: query[1], amount: query[2])
            } else if query[0] == 2 {
                printWater(in: query[1])
            }
        }
    }
    
    func printWater(in vesselIndex: Int) {
        print(waterInVessel[vesselIndex] ?? 0)
    }
}
