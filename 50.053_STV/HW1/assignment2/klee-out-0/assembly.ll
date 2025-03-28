; ModuleID = '2A.bc'
source_filename = "2A.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.cell = type { i64, %struct.cell*, %struct.cell* }

@.str = private unnamed_addr constant [37 x i8] c"0 && \22You should get out of here!!!\22\00", align 1
@.str.1 = private unnamed_addr constant [5 x i8] c"2A.c\00", align 1
@__PRETTY_FUNCTION__.test_unit = private unnamed_addr constant [28 x i8] c"void test_unit(cell *, int)\00", align 1
@.str.2 = private unnamed_addr constant [2 x i8] c"x\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @test_unit(%struct.cell* %p, i32 %x) #0 !dbg !22 {
entry:
  %p.addr = alloca %struct.cell*, align 8
  %x.addr = alloca i32, align 4
  %cur = alloca %struct.cell*, align 8
  store %struct.cell* %p, %struct.cell** %p.addr, align 8
  call void @llvm.dbg.declare(metadata %struct.cell** %p.addr, metadata !26, metadata !DIExpression()), !dbg !27
  store i32 %x, i32* %x.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %x.addr, metadata !28, metadata !DIExpression()), !dbg !29
  %call = call noalias align 16 i8* @malloc(i64 24) #5, !dbg !30
  %0 = bitcast i8* %call to %struct.cell*, !dbg !31
  store %struct.cell* %0, %struct.cell** %p.addr, align 8, !dbg !32
  %1 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !33
  %v = getelementptr inbounds %struct.cell, %struct.cell* %1, i32 0, i32 0, !dbg !34
  store i64 0, i64* %v, align 8, !dbg !35
  %2 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !36
  %prev = getelementptr inbounds %struct.cell, %struct.cell* %2, i32 0, i32 2, !dbg !37
  store %struct.cell* null, %struct.cell** %prev, align 8, !dbg !38
  %3 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !39
  %next = getelementptr inbounds %struct.cell, %struct.cell* %3, i32 0, i32 1, !dbg !40
  store %struct.cell* null, %struct.cell** %next, align 8, !dbg !41
  %4 = load i32, i32* %x.addr, align 4, !dbg !42
  %cmp = icmp sgt i32 %4, 0, !dbg !44
  br i1 %cmp, label %if.then, label %if.end6, !dbg !45

if.then:                                          ; preds = %entry
  call void @llvm.dbg.declare(metadata %struct.cell** %cur, metadata !46, metadata !DIExpression()), !dbg !48
  %5 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !49
  %6 = bitcast %struct.cell* %5 to i8*, !dbg !50
  %add.ptr = getelementptr inbounds i8, i8* %6, i64 8, !dbg !51
  %7 = bitcast i8* %add.ptr to %struct.cell*, !dbg !52
  store %struct.cell* %7, %struct.cell** %cur, align 8, !dbg !48
  %8 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !53
  %9 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !54
  %prev1 = getelementptr inbounds %struct.cell, %struct.cell* %9, i32 0, i32 2, !dbg !55
  store %struct.cell* %8, %struct.cell** %prev1, align 8, !dbg !56
  %10 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !57
  %next2 = getelementptr inbounds %struct.cell, %struct.cell* %10, i32 0, i32 1, !dbg !58
  store %struct.cell* %8, %struct.cell** %next2, align 8, !dbg !59
  %11 = load %struct.cell*, %struct.cell** %p.addr, align 8, !dbg !60
  %prev3 = getelementptr inbounds %struct.cell, %struct.cell* %11, i32 0, i32 2, !dbg !62
  %12 = load %struct.cell*, %struct.cell** %prev3, align 8, !dbg !62
  %cmp4 = icmp ne %struct.cell* %12, null, !dbg !63
  br i1 %cmp4, label %if.then5, label %if.end, !dbg !64

if.then5:                                         ; preds = %if.then
  call void @__assert_fail(i8* getelementptr inbounds ([37 x i8], [37 x i8]* @.str, i64 0, i64 0), i8* getelementptr inbounds ([5 x i8], [5 x i8]* @.str.1, i64 0, i64 0), i32 19, i8* getelementptr inbounds ([28 x i8], [28 x i8]* @__PRETTY_FUNCTION__.test_unit, i64 0, i64 0)) #6, !dbg !65
  unreachable, !dbg !65

if.end:                                           ; preds = %if.then
  br label %if.end6, !dbg !68

if.end6:                                          ; preds = %if.end, %entry
  ret void, !dbg !69
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: nounwind
declare dso_local noalias align 16 i8* @malloc(i64) #2

; Function Attrs: noreturn nounwind
declare dso_local void @__assert_fail(i8*, i8*, i32, i8*) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !70 {
entry:
  %retval = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata i32* %x, metadata !73, metadata !DIExpression()), !dbg !74
  %call = call i32 (i32*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 (i32*, i64, i8*, ...)*)(i32* %x, i64 4, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.2, i64 0, i64 0)), !dbg !75
  %0 = load i32, i32* %x, align 4, !dbg !76
  call void @test_unit(%struct.cell* null, i32 %0), !dbg !77
  ret i32 0, !dbg !78
}

declare dso_local i32 @klee_make_symbolic(...) #4

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { noreturn nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { nounwind }
attributes #6 = { noreturn nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!16, !17, !18, !19, !20}
!llvm.ident = !{!21}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, retainedTypes: !3, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "2A.c", directory: "/home/klee/HW1/assignment2")
!2 = !{}
!3 = !{!4, !13, !15}
!4 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !5, size: 64)
!5 = !DIDerivedType(tag: DW_TAG_typedef, name: "cell", file: !1, line: 9, baseType: !6)
!6 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "cell", file: !1, line: 5, size: 192, elements: !7)
!7 = !{!8, !10, !12}
!8 = !DIDerivedType(tag: DW_TAG_member, name: "v", scope: !6, file: !1, line: 6, baseType: !9, size: 64)
!9 = !DIBasicType(name: "long int", size: 64, encoding: DW_ATE_signed)
!10 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !6, file: !1, line: 7, baseType: !11, size: 64, offset: 64)
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !6, size: 64)
!12 = !DIDerivedType(tag: DW_TAG_member, name: "prev", scope: !6, file: !1, line: 8, baseType: !11, size: 64, offset: 128)
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!15 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!16 = !{i32 7, !"Dwarf Version", i32 4}
!17 = !{i32 2, !"Debug Info Version", i32 3}
!18 = !{i32 1, !"wchar_size", i32 4}
!19 = !{i32 7, !"uwtable", i32 1}
!20 = !{i32 7, !"frame-pointer", i32 2}
!21 = !{!"clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)"}
!22 = distinct !DISubprogram(name: "test_unit", scope: !1, file: !1, line: 10, type: !23, scopeLine: 10, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!23 = !DISubroutineType(types: !24)
!24 = !{null, !4, !25}
!25 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!26 = !DILocalVariable(name: "p", arg: 1, scope: !22, file: !1, line: 10, type: !4)
!27 = !DILocation(line: 10, column: 22, scope: !22)
!28 = !DILocalVariable(name: "x", arg: 2, scope: !22, file: !1, line: 10, type: !25)
!29 = !DILocation(line: 10, column: 29, scope: !22)
!30 = !DILocation(line: 12, column: 14, scope: !22)
!31 = !DILocation(line: 12, column: 5, scope: !22)
!32 = !DILocation(line: 12, column: 3, scope: !22)
!33 = !DILocation(line: 13, column: 1, scope: !22)
!34 = !DILocation(line: 13, column: 4, scope: !22)
!35 = !DILocation(line: 13, column: 6, scope: !22)
!36 = !DILocation(line: 14, column: 11, scope: !22)
!37 = !DILocation(line: 14, column: 14, scope: !22)
!38 = !DILocation(line: 14, column: 19, scope: !22)
!39 = !DILocation(line: 14, column: 1, scope: !22)
!40 = !DILocation(line: 14, column: 4, scope: !22)
!41 = !DILocation(line: 14, column: 9, scope: !22)
!42 = !DILocation(line: 15, column: 5, scope: !43)
!43 = distinct !DILexicalBlock(scope: !22, file: !1, line: 15, column: 5)
!44 = !DILocation(line: 15, column: 7, scope: !43)
!45 = !DILocation(line: 15, column: 5, scope: !22)
!46 = !DILocalVariable(name: "cur", scope: !47, file: !1, line: 16, type: !4)
!47 = distinct !DILexicalBlock(scope: !43, file: !1, line: 15, column: 12)
!48 = !DILocation(line: 16, column: 7, scope: !47)
!49 = !DILocation(line: 16, column: 30, scope: !47)
!50 = !DILocation(line: 16, column: 22, scope: !47)
!51 = !DILocation(line: 16, column: 32, scope: !47)
!52 = !DILocation(line: 16, column: 13, scope: !47)
!53 = !DILocation(line: 17, column: 25, scope: !47)
!54 = !DILocation(line: 17, column: 13, scope: !47)
!55 = !DILocation(line: 17, column: 18, scope: !47)
!56 = !DILocation(line: 17, column: 23, scope: !47)
!57 = !DILocation(line: 17, column: 1, scope: !47)
!58 = !DILocation(line: 17, column: 6, scope: !47)
!59 = !DILocation(line: 17, column: 11, scope: !47)
!60 = !DILocation(line: 18, column: 5, scope: !61)
!61 = distinct !DILexicalBlock(scope: !47, file: !1, line: 18, column: 5)
!62 = !DILocation(line: 18, column: 8, scope: !61)
!63 = !DILocation(line: 18, column: 13, scope: !61)
!64 = !DILocation(line: 18, column: 5, scope: !47)
!65 = !DILocation(line: 19, column: 1, scope: !66)
!66 = distinct !DILexicalBlock(scope: !67, file: !1, line: 19, column: 1)
!67 = distinct !DILexicalBlock(scope: !61, file: !1, line: 19, column: 1)
!68 = !DILocation(line: 20, column: 1, scope: !47)
!69 = !DILocation(line: 21, column: 1, scope: !22)
!70 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 23, type: !71, scopeLine: 23, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!71 = !DISubroutineType(types: !72)
!72 = !{!25}
!73 = !DILocalVariable(name: "x", scope: !70, file: !1, line: 24, type: !25)
!74 = !DILocation(line: 24, column: 5, scope: !70)
!75 = !DILocation(line: 25, column: 1, scope: !70)
!76 = !DILocation(line: 26, column: 17, scope: !70)
!77 = !DILocation(line: 26, column: 1, scope: !70)
!78 = !DILocation(line: 27, column: 1, scope: !70)
