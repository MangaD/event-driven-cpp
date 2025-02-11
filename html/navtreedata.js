/*
 @licstart  The following is the entire license notice for the JavaScript code in this file.

 The MIT License (MIT)

 Copyright (C) 1997-2020 by Dimitri van Heesch

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

 @licend  The above is the entire license notice for the JavaScript code in this file
*/
var NAVTREE =
[
  [ "Event-Driven Programming in C++", "index.html", [
    [ "Prerequisites", "index.html#autotoc_md1", null ],
    [ "Building the Project", "index.html#autotoc_md2", [
      [ "Configuration", "index.html#autotoc_md3", null ],
      [ "Building", "index.html#autotoc_md4", null ]
    ] ],
    [ "Running the Examples", "index.html#autotoc_md5", null ],
    [ "Running the Tests", "index.html#autotoc_md6", null ],
    [ "Test Mode for I/O and Sockets Example", "index.html#autotoc_md7", null ],
    [ "Additional Notes", "index.html#autotoc_md8", null ],
    [ "Contributing", "index.html#autotoc_md9", null ],
    [ "License", "index.html#autotoc_md10", null ],
    [ "Documentation Overview", "md_build_2md__files_2docs_2README.html", [
      [ "Directory Structure", "md_build_2md__files_2docs_2README.html#autotoc_md12", null ],
      [ "How to Use This Documentation", "md_build_2md__files_2docs_2README.html#autotoc_md13", null ],
      [ "Additional Resources", "md_build_2md__files_2docs_2README.html#autotoc_md14", null ]
    ] ],
    [ "Callbacks in C++", "md_build_2md__files_2docs_2callbacks.html", [
      [ "What Are Callbacks?", "md_build_2md__files_2docs_2callbacks.html#autotoc_md16", null ],
      [ "Approaches to Implementing Callbacks", "md_build_2md__files_2docs_2callbacks.html#autotoc_md17", [
        [ "1. Function Pointers", "md_build_2md__files_2docs_2callbacks.html#autotoc_md18", null ],
        [ "2. Lambdas", "md_build_2md__files_2docs_2callbacks.html#autotoc_md19", null ],
        [ "3. <tt>std::function</tt>", "md_build_2md__files_2docs_2callbacks.html#autotoc_md20", null ]
      ] ],
      [ "Benefits of Using Callbacks", "md_build_2md__files_2docs_2callbacks.html#autotoc_md21", null ],
      [ "When to Use Callbacks", "md_build_2md__files_2docs_2callbacks.html#autotoc_md22", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2callbacks.html#autotoc_md23", null ]
    ] ],
    [ "Design Considerations for Event-Driven Programming in C++", "md_build_2md__files_2docs_2design.html", [
      [ "Overview", "md_build_2md__files_2docs_2design.html#autotoc_md25", null ],
      [ "Key Design Patterns and Concepts", "md_build_2md__files_2docs_2design.html#autotoc_md26", [
        [ "1. Observer Pattern", "md_build_2md__files_2docs_2design.html#autotoc_md27", null ],
        [ "2. Callbacks and Function Pointers", "md_build_2md__files_2docs_2design.html#autotoc_md28", null ],
        [ "3. Qt Signal-Slot Mechanism", "md_build_2md__files_2docs_2design.html#autotoc_md29", null ],
        [ "4. I/O Event Handling with <tt>select()</tt>/<tt>poll()</tt>", "md_build_2md__files_2docs_2design.html#autotoc_md30", null ],
        [ "5. Message/Event Queues", "md_build_2md__files_2docs_2design.html#autotoc_md31", null ]
      ] ],
      [ "Architectural Considerations", "md_build_2md__files_2docs_2design.html#autotoc_md32", [
        [ "Decoupling and Modularity", "md_build_2md__files_2docs_2design.html#autotoc_md33", null ],
        [ "Concurrency and Responsiveness", "md_build_2md__files_2docs_2design.html#autotoc_md34", null ],
        [ "Error Handling and Debugging", "md_build_2md__files_2docs_2design.html#autotoc_md35", null ]
      ] ],
      [ "Best Practices", "md_build_2md__files_2docs_2design.html#autotoc_md36", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2design.html#autotoc_md37", null ]
    ] ],
    [ "Comparing Event-Driven Programming Across Languages", "md_build_2md__files_2docs_2event__driven__comparison.html", [
      [ "C++", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md40", [
        [ "Overview", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md41", null ],
        [ "Example: Observer Pattern", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md42", null ],
        [ "Pros and Cons", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md43", null ]
      ] ],
      [ "Java", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md45", [
        [ "Overview", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md46", null ],
        [ "Example: Swing Event Handling", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md47", null ],
        [ "Pros and Cons", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md48", null ]
      ] ],
      [ "Python", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md50", [
        [ "Overview", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md51", null ],
        [ "Example: Asyncio", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md52", null ],
        [ "Pros and Cons", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md53", null ]
      ] ],
      [ "JavaScript", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md55", [
        [ "Overview", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md56", null ],
        [ "Example: DOM Event in the Browser", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md57", null ],
        [ "Example: Node.js Event Emitter", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md58", null ],
        [ "Pros and Cons", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md59", null ]
      ] ],
      [ "Summary", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md61", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2event__driven__comparison.html#autotoc_md63", null ]
    ] ],
    [ "Event Queue in C++", "md_build_2md__files_2docs_2event__queue.html", [
      [ "Key Concepts", "md_build_2md__files_2docs_2event__queue.html#autotoc_md65", null ],
      [ "Benefits", "md_build_2md__files_2docs_2event__queue.html#autotoc_md66", null ],
      [ "A Simple C++ Example", "md_build_2md__files_2docs_2event__queue.html#autotoc_md67", [
        [ "Example Code", "md_build_2md__files_2docs_2event__queue.html#autotoc_md68", null ],
        [ "Explanation", "md_build_2md__files_2docs_2event__queue.html#autotoc_md69", null ]
      ] ],
      [ "Advanced Considerations", "md_build_2md__files_2docs_2event__queue.html#autotoc_md70", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2event__queue.html#autotoc_md71", null ]
    ] ],
    [ "I/O and Sockets Demonstration", "md_build_2md__files_2docs_2io__and__sockets.html", [
      [ "Overview", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md74", null ],
      [ "Key Features", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md76", null ],
      [ "Implementation Details", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md78", null ],
      [ "How to Build and Run", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md80", [
        [ "Building the Demonstration", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md81", null ],
        [ "Running the Demonstration", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md82", null ],
        [ "Interacting with the Demonstration", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md83", null ]
      ] ],
      [ "Additional Resources", "md_build_2md__files_2docs_2io__and__sockets.html#autotoc_md85", null ]
    ] ],
    [ "Observer Pattern in C++", "md_build_2md__files_2docs_2observer.html", [
      [ "Overview", "md_build_2md__files_2docs_2observer.html#autotoc_md88", [
        [ "Key Concepts", "md_build_2md__files_2docs_2observer.html#autotoc_md89", null ]
      ] ],
      [ "Benefits", "md_build_2md__files_2docs_2observer.html#autotoc_md90", null ],
      [ "When to Use the Observer Pattern", "md_build_2md__files_2docs_2observer.html#autotoc_md91", null ],
      [ "Example Implementation", "md_build_2md__files_2docs_2observer.html#autotoc_md92", null ],
      [ "How It Works", "md_build_2md__files_2docs_2observer.html#autotoc_md93", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2observer.html#autotoc_md94", null ]
    ] ],
    [ "Observer Pattern vs. Callbacks: A Comparison", "md_build_2md__files_2docs_2observer__vs__callbacks.html", [
      [ "Observer Pattern", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md97", [
        [ "Pros", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md98", null ],
        [ "Cons", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md99", null ]
      ] ],
      [ "Callbacks", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md101", [
        [ "Pros", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md102", null ],
        [ "Cons", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md103", null ]
      ] ],
      [ "How to Choose", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md105", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2observer__vs__callbacks.html#autotoc_md107", null ]
    ] ],
    [ "Qt Signals & Slots in C++", "md_build_2md__files_2docs_2qt__signals.html", [
      [ "What Are Signals and Slots?", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md109", null ],
      [ "Key Features of Qt's Signal-Slot Mechanism", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md110", null ],
      [ "Setting Up a Qt Project", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md111", null ],
      [ "Example: A Simple Signal-Slot Implementation", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md112", [
        [ "Sender Class", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md113", null ],
        [ "Receiver Class", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md114", null ],
        [ "Main File", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md115", null ]
      ] ],
      [ "Explanation", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md116", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2qt__signals.html#autotoc_md117", null ]
    ] ],
    [ "Setup Guide for Event-Driven Programming in C++", "md_build_2md__files_2docs_2setup.html", [
      [ "Prerequisites", "md_build_2md__files_2docs_2setup.html#autotoc_md120", null ],
      [ "Cloning the Repository", "md_build_2md__files_2docs_2setup.html#autotoc_md122", null ],
      [ "Using CMake Presets", "md_build_2md__files_2docs_2setup.html#autotoc_md124", [
        [ "To Configure the Project", "md_build_2md__files_2docs_2setup.html#autotoc_md125", null ],
        [ "To Build the Project", "md_build_2md__files_2docs_2setup.html#autotoc_md126", null ]
      ] ],
      [ "Automatic Deployment on Windows", "md_build_2md__files_2docs_2setup.html#autotoc_md128", [
        [ "Note on Qt6_DIR and VCINSTALLDIR", "md_build_2md__files_2docs_2setup.html#autotoc_md129", null ]
      ] ],
      [ "Running the Application", "md_build_2md__files_2docs_2setup.html#autotoc_md131", null ],
      [ "Summary", "md_build_2md__files_2docs_2setup.html#autotoc_md133", null ]
    ] ],
    [ "Event-Driven Programming in C++", "md_build_2md__files_2docs_2what__is__event__driven__programming.html", [
      [ "Key Concepts", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md135", null ],
      [ "How Event-Driven Programming Works", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md136", [
        [ "Example: GUI Application", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md137", null ],
        [ "Example: Network Server", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md138", null ]
      ] ],
      [ "Event-Driven Programming vs. Event-Driven Architecture", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md139", null ],
      [ "Benefits of Event-Driven Programming", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md140", null ],
      [ "Challenges", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md141", null ],
      [ "Conclusion", "md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md142", null ]
    ] ],
    [ "Callbacks Example", "md_src_2callbacks_2README.html", [
      [ "Contents", "md_src_2callbacks_2README.html#autotoc_md144", null ],
      [ "Building the Example", "md_src_2callbacks_2README.html#autotoc_md145", null ],
      [ "Running the Example", "md_src_2callbacks_2README.html#autotoc_md146", null ],
      [ "Overview", "md_src_2callbacks_2README.html#autotoc_md147", null ]
    ] ],
    [ "Common Utilities", "md_src_2common_2README.html", [
      [ "Contents", "md_src_2common_2README.html#autotoc_md149", null ],
      [ "Usage", "md_src_2common_2README.html#autotoc_md150", null ],
      [ "Building", "md_src_2common_2README.html#autotoc_md151", null ],
      [ "License", "md_src_2common_2README.html#autotoc_md152", null ]
    ] ],
    [ "Event Queue Example", "md_src_2event__queue_2README.html", [
      [ "Contents", "md_src_2event__queue_2README.html#autotoc_md155", null ],
      [ "Building the Example", "md_src_2event__queue_2README.html#autotoc_md157", [
        [ "Manual Build Steps", "md_src_2event__queue_2README.html#autotoc_md158", null ]
      ] ],
      [ "Running the Example", "md_src_2event__queue_2README.html#autotoc_md160", null ],
      [ "Overview", "md_src_2event__queue_2README.html#autotoc_md162", null ],
      [ "License", "md_src_2event__queue_2README.html#autotoc_md164", null ]
    ] ],
    [ "I/O and Sockets Demonstration", "md_src_2io__and__sockets_2README.html", [
      [ "Contents", "md_src_2io__and__sockets_2README.html#autotoc_md167", null ],
      [ "Building the Demonstration", "md_src_2io__and__sockets_2README.html#autotoc_md169", [
        [ "Using CMake Presets", "md_src_2io__and__sockets_2README.html#autotoc_md170", null ],
        [ "Manual Build Steps", "md_src_2io__and__sockets_2README.html#autotoc_md171", null ]
      ] ],
      [ "Running the Demonstration", "md_src_2io__and__sockets_2README.html#autotoc_md173", null ],
      [ "Additional Information", "md_src_2io__and__sockets_2README.html#autotoc_md175", null ]
    ] ],
    [ "Observer Pattern Example", "md_src_2observer_2README.html", [
      [ "Contents", "md_src_2observer_2README.html#autotoc_md177", null ],
      [ "Building the Example", "md_src_2observer_2README.html#autotoc_md178", null ],
      [ "Running the Example", "md_src_2observer_2README.html#autotoc_md179", null ],
      [ "Overview of the Observer Pattern", "md_src_2observer_2README.html#autotoc_md180", null ]
    ] ],
    [ "Qt Signals & Slots Example", "md_src_2qt__signals_2README.html", [
      [ "Contents", "md_src_2qt__signals_2README.html#autotoc_md183", null ],
      [ "Building the Example", "md_src_2qt__signals_2README.html#autotoc_md184", [
        [ "Prerequisites", "md_src_2qt__signals_2README.html#autotoc_md185", null ],
        [ "Build Steps", "md_src_2qt__signals_2README.html#autotoc_md186", null ]
      ] ],
      [ "Running the Example", "md_src_2qt__signals_2README.html#autotoc_md187", null ],
      [ "Overview of the Example", "md_src_2qt__signals_2README.html#autotoc_md188", null ],
      [ "Additional Resources", "md_src_2qt__signals_2README.html#autotoc_md189", null ]
    ] ],
    [ "Namespaces", "namespaces.html", [
      [ "Namespace List", "namespaces.html", "namespaces_dup" ],
      [ "Namespace Members", "namespacemembers.html", [
        [ "All", "namespacemembers.html", null ],
        [ "Functions", "namespacemembers_func.html", null ],
        [ "Enumerations", "namespacemembers_enum.html", null ]
      ] ]
    ] ],
    [ "Classes", "annotated.html", [
      [ "Class List", "annotated.html", "annotated_dup" ],
      [ "Class Index", "classes.html", null ],
      [ "Class Hierarchy", "hierarchy.html", "hierarchy" ],
      [ "Class Members", "functions.html", [
        [ "All", "functions.html", null ],
        [ "Functions", "functions_func.html", null ],
        [ "Variables", "functions_vars.html", null ],
        [ "Typedefs", "functions_type.html", null ]
      ] ]
    ] ],
    [ "Files", "files.html", [
      [ "File List", "files.html", "files_dup" ],
      [ "File Members", "globals.html", [
        [ "All", "globals.html", null ],
        [ "Functions", "globals_func.html", null ],
        [ "Variables", "globals_vars.html", null ],
        [ "Macros", "globals_defs.html", null ]
      ] ]
    ] ]
  ] ]
];

var NAVTREEINDEX =
[
"annotated.html",
"md_build_2md__files_2docs_2what__is__event__driven__programming.html#autotoc_md141"
];

var SYNCONMSG = 'click to disable panel synchronisation';
var SYNCOFFMSG = 'click to enable panel synchronisation';