; ModuleID = '1C.bc'
source_filename = "1C.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [9 x i8] c"y <= 100\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"1C.c\00", align 1
@__PRETTY_FUNCTION__.test_loop = private unnamed_addr constant [21 x i8] c"int test_loop(int *)\00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"a\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @test_loop(i32* %a) #0 !dbg !9 {
entry:
  %a.addr = alloca i32*, align 8
  %y = alloca i32, align 4
  %i = alloca i32, align 4
  store i32* %a, i32** %a.addr, align 8
  call void @llvm.dbg.declare(metadata i32** %a.addr, metadata !14, metadata !DIExpression()), !dbg !15
  call void @llvm.dbg.declare(metadata i32* %y, metadata !16, metadata !DIExpression()), !dbg !17
  store i32 0, i32* %y, align 4, !dbg !17
  call void @llvm.dbg.declare(metadata i32* %i, metadata !18, metadata !DIExpression()), !dbg !19
  store i32 0, i32* %i, align 4, !dbg !19
  br label %while.cond, !dbg !20

while.cond:                                       ; preds = %while.body, %entry
  %0 = load i32, i32* %i, align 4, !dbg !21
  %cmp = icmp slt i32 %0, 100, !dbg !22
  br i1 %cmp, label %while.body, label %while.end, !dbg !20

while.body:                                       ; preds = %while.cond
  %1 = load i32, i32* %y, align 4, !dbg !23
  %inc = add nsw i32 %1, 1, !dbg !23
  store i32 %inc, i32* %y, align 4, !dbg !23
  %2 = load i32, i32* %i, align 4, !dbg !25
  %inc1 = add nsw i32 %2, 1, !dbg !25
  store i32 %inc1, i32* %i, align 4, !dbg !25
  br label %while.cond, !dbg !20, !llvm.loop !26

while.end:                                        ; preds = %while.cond
  %3 = load i32, i32* %y, align 4, !dbg !29
  %cmp2 = icmp sle i32 %3, 100, !dbg !29
  br i1 %cmp2, label %if.then, label %if.else, !dbg !32

if.then:                                          ; preds = %while.end
  br label %if.end, !dbg !32

if.else:                                          ; preds = %while.end
  call void @__assert_fail(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i32 11, i8* getelementptr inbounds ([21 x i8], [21 x i8]* @__PRETTY_FUNCTION__.test_loop, i64 0, i64 0)) #4, !dbg !29
  unreachable, !dbg !29

if.end:                                           ; preds = %if.then
  %4 = load i32, i32* %y, align 4, !dbg !33
  ret i32 %4, !dbg !34
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noreturn nounwind
declare dso_local void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !35 {
entry:
  %retval = alloca i32, align 4
  %a = alloca [100 x i32], align 16
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [100 x i32]* %a, metadata !38, metadata !DIExpression()), !dbg !42
  %call = call i32 ([100 x i32]*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 ([100 x i32]*, i64, i8*, ...)*)([100 x i32]* %a, i64 400, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i64 0, i64 0)), !dbg !43
  %arraydecay = getelementptr inbounds [100 x i32], [100 x i32]* %a, i64 0, i64 0, !dbg !44
  %call1 = call i32 @test_loop(i32* %arraydecay), !dbg !45
  ret i32 %call1, !dbg !46
}

declare dso_local i32 @klee_make_symbolic(...) #3

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { noreturn nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noreturn nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!3, !4, !5, !6, !7}
!llvm.ident = !{!8}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "1C.c", directory: "/home/klee/HW1/assignment1")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{i32 7, !"uwtable", i32 1}
!7 = !{i32 7, !"frame-pointer", i32 2}
!8 = !{!"clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)"}
!9 = distinct !DISubprogram(name: "test_loop", scope: !1, file: !1, line: 4, type: !10, scopeLine: 4, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!10 = !DISubroutineType(types: !11)
!11 = !{!12, !13}
!12 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!14 = !DILocalVariable(name: "a", arg: 1, scope: !9, file: !1, line: 4, type: !13)
!15 = !DILocation(line: 4, column: 19, scope: !9)
!16 = !DILocalVariable(name: "y", scope: !9, file: !1, line: 5, type: !12)
!17 = !DILocation(line: 5, column: 9, scope: !9)
!18 = !DILocalVariable(name: "i", scope: !9, file: !1, line: 6, type: !12)
!19 = !DILocation(line: 6, column: 9, scope: !9)
!20 = !DILocation(line: 7, column: 5, scope: !9)
!21 = !DILocation(line: 7, column: 12, scope: !9)
!22 = !DILocation(line: 7, column: 14, scope: !9)
!23 = !DILocation(line: 8, column: 10, scope: !24)
!24 = distinct !DILexicalBlock(scope: !9, file: !1, line: 7, column: 21)
!25 = !DILocation(line: 9, column: 10, scope: !24)
!26 = distinct !{!26, !20, !27, !28}
!27 = !DILocation(line: 10, column: 5, scope: !9)
!28 = !{!"llvm.loop.mustprogress"}
!29 = !DILocation(line: 11, column: 5, scope: !30)
!30 = distinct !DILexicalBlock(scope: !31, file: !1, line: 11, column: 5)
!31 = distinct !DILexicalBlock(scope: !9, file: !1, line: 11, column: 5)
!32 = !DILocation(line: 11, column: 5, scope: !31)
!33 = !DILocation(line: 12, column: 12, scope: !9)
!34 = !DILocation(line: 12, column: 5, scope: !9)
!35 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 15, type: !36, scopeLine: 15, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!36 = !DISubroutineType(types: !37)
!37 = !{!12}
!38 = !DILocalVariable(name: "a", scope: !35, file: !1, line: 16, type: !39)
!39 = !DICompositeType(tag: DW_TAG_array_type, baseType: !12, size: 3200, elements: !40)
!40 = !{!41}
!41 = !DISubrange(count: 100)
!42 = !DILocation(line: 16, column: 9, scope: !35)
!43 = !DILocation(line: 17, column: 5, scope: !35)
!44 = !DILocation(line: 18, column: 22, scope: !35)
!45 = !DILocation(line: 18, column: 12, scope: !35)
!46 = !DILocation(line: 18, column: 5, scope: !35)
