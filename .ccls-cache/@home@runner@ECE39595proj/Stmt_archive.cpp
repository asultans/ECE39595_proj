// #include "Stmt.h"
// #include "Symtbl.h"
// #include <fstream>

// void Stmt::serialize(std::ofstream *aout_fil) {

//   ofstream fl;
//   fl.open(aout_file);
//   if (!fl) {
//     printf("error with output file\n");
//   } else {
//     // determine op_code and print accordingly

//     // this if is for mem prints
//     if ((op_add == 21) || op_add == 23) {
//       if (op_add == 21) {
//         fl << "GoSub " + name + "(" + mem + ")" + "\n";
//       } else {
//         fl << "Start " + mem + "\n";
//       }
//     }

//     // this if is for location based prints
//     // this has jumps, pops and pushs
//     else if (op_add == (16 || 17 || 18 || 19 || 32 || 33 || 34 || 48 || 49)) {
//       if (op_add == 16) {
//         fl << "Jump, " + location + "\n";
//       } else if (op_add == 17) {
//         fl << "JumpZero, " + name + ", (" + location + ")\n";
//       } else if (op_add == 18) {
//         fl << "JumpNZero, " + name + ", (" + location + ")\n";

//       } else if (op_add == 19) {
//         fl << "GoSubLabel , " + name + "\n";
//       } else if (op_add == 32) {
//         fl << "PushScalar " + name + ", (" + location + ")\n";
//       } else if (op_add == 33) {
//         fl << "PushArray " + name + ", (" + location + ")\n";
//       } else if (op_add == 34) {
//         fl << "PushI  " + "(" + pushi + ")\n";
//       } else if (op_add == 48) {
//         fl << "PopScalar " + name + ", (" + location + ")\n";
//       } else {
//         fl << "PopArray " + name + ", (" + location + ")\n";
//       }

//     }

//     // this is going to just do basic print op_code name
//     else if (op_add == 96) {
//       fl << "Prints " + print + "\n"
//     } else if (op_add == 97) {
//       fl << "PrintTOS\n";
//     } else if (op_add == 22) {
//       fl << "Return\n";
//     } else if (op_add == 24) {
//       fl << "Exit\n";
//     } else if (op_add == 64) {
//       fl << "Dup\n";
//     } else if (op_add == 65) {
//       fl << "Swap\n";
//     } else if (op_add == 80) {
//       fl << "Add\n";
//     } else if (op_add == 81) {
//       fl << "Negate\n";
//     } else if (op_add == 82) {
//       fl << "Mul\n";
//     } else if (op_add == 83) {
//       fl << "Div\n";
//     } else {
//       fl << "Op code not accounted for " + op_add + "\n";
//     }
//   }
//   fl.close(aout_file);
// };

// // Stmt::Stmt(int op_add_) 
// //   : op_add(op_add_){
// //     mem = -1;
// //     push_i = -1;
// //     initialize = false;
// //     print = "wrong";

