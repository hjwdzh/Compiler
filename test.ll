; ModuleID = 'test.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.8.0"

@.str0 = private unnamed_addr constant [5 x i8] c"%lf\0A\00", align 1

define i32 @main() nounwind ssp uwtable{
  %t = alloca i32, align 4
  store i32 3, i32* %t, align 4
  %l = alloca double, align 8
  store double 3.500000, double* %l, align 8
  %1 = load i32* %t, align 4
  %2 = sitofp i32 %1 to double
  store double %2, double* %l, align 8
  %3 = load double* %l, align 8
  %4 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @.str0, i32 0, i32 0), double %3)
  ret i32 0
}
declare i32 @printf(i8*, ...)
declare i32 @scanf(i8*, ...)
declare i8* @malloc(i64)
declare i32 @free(...)
