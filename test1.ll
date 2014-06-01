; ModuleID = 'test.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.8.0"

define i32 @main() nounwind ssp uwtable {
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  br label %1
; <label>:1
  %2 = load i32* %i, align 4
  %3 = icmp slt i32 %2, 9
  br i1 %3, label %4, label %5
; <label>:4
  br label %1
; <label>:5
  %6 = load i32* %i, align 4
  %7 = icmp slt i32 %6, 9
  br i1 %7, label %8, label %10

; <label>:8
  %9 = load i32* %i, align 4
  store i32 %9, i32* %i, align 4
  br label %10

; <label>:10
  ret i32 0
}
