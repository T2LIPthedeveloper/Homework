; ModuleID = '1A.bc'
source_filename = "1A.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [9 x i8] c"y <= 100\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"1A.c\00", align 1
@__PRETTY_FUNCTION__.test_loop = private unnamed_addr constant [21 x i8] c"int test_loop(int *)\00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"a\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @test_loop(i32* %a) #0 !dbg !9 {
entry:
  %retval = alloca i32, align 4
  %a.addr = alloca i32*, align 8
  %y = alloca i32, align 4
  %i = alloca i32, align 4
  store i32* %a, i32** %a.addr, align 8
  call void @llvm.dbg.declare(metadata i32** %a.addr, metadata !14, metadata !DIExpression()), !dbg !15
  call void @llvm.dbg.declare(metadata i32* %y, metadata !16, metadata !DIExpression()), !dbg !17
  call void @llvm.dbg.declare(metadata i32* %i, metadata !18, metadata !DIExpression()), !dbg !19
  store i32 0, i32* %i, align 4, !dbg !19
  br label %while.cond, !dbg !20

while.cond:                                       ; preds = %if.end, %entry
  %0 = load i32, i32* %i, align 4, !dbg !21
  %cmp = icmp slt i32 %0, 100, !dbg !22
  br i1 %cmp, label %while.body, label %while.end, !dbg !20

while.body:                                       ; preds = %while.cond
  %1 = load i32*, i32** %a.addr, align 8, !dbg !23
  %2 = load i32, i32* %i, align 4, !dbg !26
  %idxprom = sext i32 %2 to i64, !dbg !23
  %arrayidx = getelementptr inbounds i32, i32* %1, i64 %idxprom, !dbg !23
  %3 = load i32, i32* %arrayidx, align 4, !dbg !23
  %cmp1 = icmp slt i32 %3, 10, !dbg !27
  br i1 %cmp1, label %if.then, label %if.else, !dbg !28

if.then:                                          ; preds = %while.body
  %4 = load i32, i32* %y, align 4, !dbg !29
  %inc = add nsw i32 %4, 1, !dbg !29
  store i32 %inc, i32* %y, align 4, !dbg !29
  br label %if.end, !dbg !30

if.else:                                          ; preds = %while.body
  %5 = load i32, i32* %y, align 4, !dbg !31
  %dec = add nsw i32 %5, -1, !dbg !31
  store i32 %dec, i32* %y, align 4, !dbg !31
  br label %if.end

if.end:                                           ; preds = %if.else, %if.then
  %6 = load i32, i32* %i, align 4, !dbg !32
  %inc2 = add nsw i32 %6, 1, !dbg !32
  store i32 %inc2, i32* %i, align 4, !dbg !32
  br label %while.cond, !dbg !20, !llvm.loop !33

while.end:                                        ; preds = %while.cond
  %7 = load i32, i32* %y, align 4, !dbg !36
  %cmp3 = icmp sle i32 %7, 100, !dbg !36
  br i1 %cmp3, label %if.then4, label %if.else5, !dbg !39

if.then4:                                         ; preds = %while.end
  br label %if.end6, !dbg !39

if.else5:                                         ; preds = %while.end
  call void @__assert_fail(i8* getelementptr inbounds ([9 x i8], [9 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i32 17, i8* getelementptr inbounds ([21 x i8], [21 x i8]* @__PRETTY_FUNCTION__.test_loop, i64 0, i64 0)) #4, !dbg !36
  unreachable, !dbg !36

if.end6:                                          ; preds = %if.then4
  %8 = load i32, i32* %retval, align 4, !dbg !40
  ret i32 %8, !dbg !40
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: noreturn nounwind
declare dso_local void @__assert_fail(i8*, i8*, i32, i8*) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !41 {
entry:
  %retval = alloca i32, align 4
  %a = alloca [100 x i32], align 16
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata [100 x i32]* %a, metadata !44, metadata !DIExpression()), !dbg !48
  %arraydecay = getelementptr inbounds [100 x i32], [100 x i32]* %a, i64 0, i64 0, !dbg !49
  %call = call i32 (i32*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 (i32*, i64, i8*, ...)*)(i32* %arraydecay, i64 400, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i64 0, i64 0)), !dbg !50
  %arraydecay1 = getelementptr inbounds [100 x i32], [100 x i32]* %a, i64 0, i64 0, !dbg !51
  %call2 = call i32 @test_loop(i32* %arraydecay1), !dbg !52
  ret i32 0, !dbg !53
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
!1 = !DIFile(filename: "1A.c", directory: "/home/klee/HW1/assignment1")
!2 = !{}
!3 = !{i32 7, !"Dwarf Version", i32 4}
!4 = !{i32 2, !"Debug Info Version", i32 3}
!5 = !{i32 1, !"wchar_size", i32 4}
!6 = !{i32 7, !"uwtable", i32 1}
!7 = !{i32 7, !"frame-pointer", i32 2}
!8 = !{!"clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)"}
!9 = distinct !DISubprogram(name: "test_loop", scope: !1, file: !1, line: 5, type: !10, scopeLine: 6, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!10 = !DISubroutineType(types: !11)
!11 = !{!12, !13}
!12 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !12, size: 64)
!14 = !DILocalVariable(name: "a", arg: 1, scope: !9, file: !1, line: 5, type: !13)
!15 = !DILocation(line: 5, column: 19, scope: !9)
!16 = !DILocalVariable(name: "y", scope: !9, file: !1, line: 7, type: !12)
!17 = !DILocation(line: 7, column: 9, scope: !9)
!18 = !DILocalVariable(name: "i", scope: !9, file: !1, line: 8, type: !12)
!19 = !DILocation(line: 8, column: 9, scope: !9)
!20 = !DILocation(line: 9, column: 5, scope: !9)
!21 = !DILocation(line: 9, column: 12, scope: !9)
!22 = !DILocation(line: 9, column: 14, scope: !9)
!23 = !DILocation(line: 11, column: 13, scope: !24)
!24 = distinct !DILexicalBlock(scope: !25, file: !1, line: 11, column: 13)
!25 = distinct !DILexicalBlock(scope: !9, file: !1, line: 10, column: 5)
!26 = !DILocation(line: 11, column: 15, scope: !24)
!27 = !DILocation(line: 11, column: 18, scope: !24)
!28 = !DILocation(line: 11, column: 13, scope: !25)
!29 = !DILocation(line: 12, column: 14, scope: !24)
!30 = !DILocation(line: 12, column: 13, scope: !24)
!31 = !DILocation(line: 14, column: 14, scope: !24)
!32 = !DILocation(line: 15, column: 10, scope: !25)
!33 = distinct !{!33, !20, !34, !35}
!34 = !DILocation(line: 16, column: 5, scope: !9)
!35 = !{!"llvm.loop.mustprogress"}
!36 = !DILocation(line: 17, column: 5, scope: !37)
!37 = distinct !DILexicalBlock(scope: !38, file: !1, line: 17, column: 5)
!38 = distinct !DILexicalBlock(scope: !9, file: !1, line: 17, column: 5)
!39 = !DILocation(line: 17, column: 5, scope: !38)
!40 = !DILocation(line: 18, column: 1, scope: !9)
!41 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 20, type: !42, scopeLine: 21, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!42 = !DISubroutineType(types: !43)
!43 = !{!12}
!44 = !DILocalVariable(name: "a", scope: !41, file: !1, line: 22, type: !45)
!45 = !DICompositeType(tag: DW_TAG_array_type, baseType: !12, size: 3200, elements: !46)
!46 = !{!47}
!47 = !DISubrange(count: 100)
!48 = !DILocation(line: 22, column: 9, scope: !41)
!49 = !DILocation(line: 23, column: 24, scope: !41)
!50 = !DILocation(line: 23, column: 5, scope: !41)
!51 = !DILocation(line: 24, column: 15, scope: !41)
!52 = !DILocation(line: 24, column: 5, scope: !41)
!53 = !DILocation(line: 25, column: 5, scope: !41)
