//
//  ContentView.swift
//  Algorithms
//
//  Created by Tiko on 5/31/23.
//

import SwiftUI

struct ContentView: View {
    @State private var model: ContentViewModel = ContentViewModel()
    
    var body: some View {
        VStack {
            Text("Algorithmic Problems with GamZaza")
            List {
                Text("Recursion").bold()
                ForEach(model.problems, id: \.self) { problem in
                    VStack{
                        HStack(alignment: .center) {
                            Text(problem.tag)
                            Text(problem.name)
                            if let link = problem.link {
                                Link(destination: link) {
                                    Image(systemName: "link")
                                        .font(.system(size: 18))
                                }
                            }
                            Spacer()
                            Image(systemName: problem.status ? "checkmark" : "xmark")
                                .font(.system(size: 24))
                                .foregroundColor(problem.status ? .green : .red)
                            Button {
                                VesselSolution().solution()
                            } label: {
                                Text("try").font(.system(size: 18))
                            }

                        }
                    }
                }
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}


class ContentViewModel {
    var problems: [Problem] = [Problem("Taxi Problem",
                                       false, 1,
                                       ProblemURLs.taxiProblem.url,
                                       .codeforce),
                               Problem("Maze Problem",
                                       true, 2,
                                       ProblemURLs.mazeProblem.url,
                                       .codeforce),
                               Problem("Worms",
                                       false,
                                       3,
                                       ProblemURLs.wormsProblem.url,
                                       .codeforce),
                               Problem("Lake Counting",
                                       false,
                                       4,
                                       ProblemURLs.lakeCountingProblem.url,
                                       .poj),
                               Problem("Vessel problem",
                                       false,
                                       4,
                                       ProblemURLs.lakeCountingProblem.url,
                                       .poj)]
}


struct Problem: Identifiable, Hashable {
    let id = UUID()
    let name: String
    let status: Bool
    let tag: String
    let link: URL?
    let source: Source
    
    init(_ name: String, _ status: Bool, _ tag: Int, _ link: URL?, _ source: Source) {
        self.name = name
        self.status = status
        self.tag = "\(tag). "
        self.link = link
        self.source = source
    }
}


enum Source: String {
    case codeforce, informatics, eolymp, poj, usaco, youtube, replit
}



enum ProblemURLs: String {
case taxiProblem = "https://codeforces.com/problemset/problem/158/B"
case mazeProblem = "https://codeforces.com/problemset/problem/377/A"
case wormsProblem = "https://codeforces.com/problemset/problem/474/B?locale=en"
case lakeCountingProblem = "http://poj.org/problem?id=2386"
case vesselProblem = "https://codeforces.com/problemset/problem/371/D"
    
    var url: URL? {
        return self.rawValue.url
    }
}


extension String {
    var url: URL? {
        return URL(string: self)
    }
}
