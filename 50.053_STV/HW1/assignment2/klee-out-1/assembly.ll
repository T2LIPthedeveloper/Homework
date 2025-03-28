; ModuleID = '2D.bc'
source_filename = "2D.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, %struct._IO_codecvt*, %struct._IO_wide_data*, %struct._IO_FILE*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type opaque
%struct._IO_codecvt = type opaque
%struct._IO_wide_data = type opaque
%struct.cell = type { i64, %struct.cell*, %struct.cell* }

@stderr = external dso_local global %struct._IO_FILE*, align 8
@.str = private unnamed_addr constant [26 x i8] c"Memory allocation failed\0A\00", align 1
@.str.1 = private unnamed_addr constant [2 x i8] c"x\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @test_unit(i32 %x) #0 !dbg !19 {
entry:
  %retval = alloca i32, align 4
  %x.addr = alloca i32, align 4
  %p = alloca %struct.cell*, align 8
  %cur = alloca %struct.cell*, align 8
  store i32 %x, i32* %x.addr, align 4
  call void @llvm.dbg.declare(metadata i32* %x.addr, metadata !23, metadata !DIExpression()), !dbg !24
  call void @llvm.dbg.declare(metadata %struct.cell** %p, metadata !25, metadata !DIExpression()), !dbg !26
  %call = call noalias align 16 i8* @malloc(i64 24) #4, !dbg !27
  %0 = bitcast i8* %call to %struct.cell*, !dbg !28
  store %struct.cell* %0, %struct.cell** %p, align 8, !dbg !26
  %1 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !29
  %tobool = icmp ne %struct.cell* %1, null, !dbg !29
  br i1 %tobool, label %if.end, label %if.then, !dbg !31

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8, !dbg !32
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0)), !dbg !34
  store i32 -1, i32* %retval, align 4, !dbg !35
  br label %return, !dbg !35

if.end:                                           ; preds = %entry
  %3 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !36
  %v = getelementptr inbounds %struct.cell, %struct.cell* %3, i32 0, i32 0, !dbg !37
  store i64 0, i64* %v, align 8, !dbg !38
  %4 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !39
  %prev = getelementptr inbounds %struct.cell, %struct.cell* %4, i32 0, i32 2, !dbg !40
  store %struct.cell* null, %struct.cell** %prev, align 8, !dbg !41
  %5 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !42
  %next = getelementptr inbounds %struct.cell, %struct.cell* %5, i32 0, i32 1, !dbg !43
  store %struct.cell* null, %struct.cell** %next, align 8, !dbg !44
  %6 = load i32, i32* %x.addr, align 4, !dbg !45
  %cmp = icmp sgt i32 %6, 0, !dbg !47
  br i1 %cmp, label %if.then2, label %if.end11, !dbg !48

if.then2:                                         ; preds = %if.end
  call void @llvm.dbg.declare(metadata %struct.cell** %cur, metadata !49, metadata !DIExpression()), !dbg !51
  %call3 = call noalias align 16 i8* @malloc(i64 24) #4, !dbg !52
  %7 = bitcast i8* %call3 to %struct.cell*, !dbg !53
  store %struct.cell* %7, %struct.cell** %cur, align 8, !dbg !51
  %8 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !54
  %tobool4 = icmp ne %struct.cell* %8, null, !dbg !54
  br i1 %tobool4, label %if.end7, label %if.then5, !dbg !56

if.then5:                                         ; preds = %if.then2
  %9 = load %struct._IO_FILE*, %struct._IO_FILE** @stderr, align 8, !dbg !57
  %call6 = call i32 (%struct._IO_FILE*, i8*, ...) @fprintf(%struct._IO_FILE* %9, i8* getelementptr inbounds ([26 x i8], [26 x i8]* @.str, i64 0, i64 0)), !dbg !59
  %10 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !60
  %11 = bitcast %struct.cell* %10 to i8*, !dbg !60
  call void @free(i8* %11) #4, !dbg !61
  store i32 -1, i32* %retval, align 4, !dbg !62
  br label %return, !dbg !62

if.end7:                                          ; preds = %if.then2
  %12 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !63
  %13 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !64
  %prev8 = getelementptr inbounds %struct.cell, %struct.cell* %13, i32 0, i32 2, !dbg !65
  store %struct.cell* %12, %struct.cell** %prev8, align 8, !dbg !66
  %14 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !67
  %next9 = getelementptr inbounds %struct.cell, %struct.cell* %14, i32 0, i32 1, !dbg !68
  store %struct.cell* %12, %struct.cell** %next9, align 8, !dbg !69
  %15 = load %struct.cell*, %struct.cell** %cur, align 8, !dbg !70
  %16 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !71
  %prev10 = getelementptr inbounds %struct.cell, %struct.cell* %16, i32 0, i32 2, !dbg !72
  store %struct.cell* %15, %struct.cell** %prev10, align 8, !dbg !73
  br label %if.end11, !dbg !74

if.end11:                                         ; preds = %if.end7, %if.end
  %17 = load %struct.cell*, %struct.cell** %p, align 8, !dbg !75
  %18 = bitcast %struct.cell* %17 to i8*, !dbg !75
  call void @free(i8* %18) #4, !dbg !76
  store i32 0, i32* %retval, align 4, !dbg !77
  br label %return, !dbg !77

return:                                           ; preds = %if.end11, %if.then5, %if.then
  %19 = load i32, i32* %retval, align 4, !dbg !78
  ret i32 %19, !dbg !78
}

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

; Function Attrs: nounwind
declare dso_local noalias align 16 i8* @malloc(i64) #2

declare dso_local i32 @fprintf(%struct._IO_FILE*, i8*, ...) #3

; Function Attrs: nounwind
declare dso_local void @free(i8*) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !79 {
entry:
  %retval = alloca i32, align 4
  %x = alloca i32, align 4
  %ret = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  call void @llvm.dbg.declare(metadata i32* %x, metadata !82, metadata !DIExpression()), !dbg !83
  call void @llvm.dbg.declare(metadata i32* %ret, metadata !84, metadata !DIExpression()), !dbg !85
  %call = call i32 (i32*, i64, i8*, ...) bitcast (i32 (...)* @klee_make_symbolic to i32 (i32*, i64, i8*, ...)*)(i32* %x, i64 4, i8* getelementptr inbounds ([2 x i8], [2 x i8]* @.str.1, i64 0, i64 0)), !dbg !86
  %0 = load i32, i32* %x, align 4, !dbg !87
  %call1 = call i32 @test_unit(i32 %0), !dbg !88
  store i32 %call1, i32* %ret, align 4, !dbg !89
  %1 = load i32, i32* %ret, align 4, !dbg !90
  %cmp = icmp ne i32 %1, 0, !dbg !92
  br i1 %cmp, label %if.then, label %if.end, !dbg !93

if.then:                                          ; preds = %entry
  store i32 1, i32* %retval, align 4, !dbg !94
  br label %return, !dbg !94

if.end:                                           ; preds = %entry
  store i32 0, i32* %retval, align 4, !dbg !96
  br label %return, !dbg !96

return:                                           ; preds = %if.end, %if.then
  %2 = load i32, i32* %retval, align 4, !dbg !97
  ret i32 %2, !dbg !97
}

declare dso_local i32 @klee_make_symbolic(...) #3

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nofree nosync nounwind readnone speculatable willreturn }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!13, !14, !15, !16, !17}
!llvm.ident = !{!18}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !2, retainedTypes: !3, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "2D.c", directory: "/home/klee/HW1/assignment2")
!2 = !{}
!3 = !{!4}
!4 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !5, size: 64)
!5 = !DIDerivedType(tag: DW_TAG_typedef, name: "cell", file: !1, line: 10, baseType: !6)
!6 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "cell", file: !1, line: 6, size: 192, elements: !7)
!7 = !{!8, !10, !12}
!8 = !DIDerivedType(tag: DW_TAG_member, name: "v", scope: !6, file: !1, line: 7, baseType: !9, size: 64)
!9 = !DIBasicType(name: "long int", size: 64, encoding: DW_ATE_signed)
!10 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !6, file: !1, line: 8, baseType: !11, size: 64, offset: 64)
!11 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !6, size: 64)
!12 = !DIDerivedType(tag: DW_TAG_member, name: "prev", scope: !6, file: !1, line: 9, baseType: !11, size: 64, offset: 128)
!13 = !{i32 7, !"Dwarf Version", i32 4}
!14 = !{i32 2, !"Debug Info Version", i32 3}
!15 = !{i32 1, !"wchar_size", i32 4}
!16 = !{i32 7, !"uwtable", i32 1}
!17 = !{i32 7, !"frame-pointer", i32 2}
!18 = !{!"clang version 13.0.1 (https://github.com/llvm/llvm-project.git 75e33f71c2dae584b13a7d1186ae0a038ba98838)"}
!19 = distinct !DISubprogram(name: "test_unit", scope: !1, file: !1, line: 12, type: !20, scopeLine: 13, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!20 = !DISubroutineType(types: !21)
!21 = !{!22, !22}
!22 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!23 = !DILocalVariable(name: "x", arg: 1, scope: !19, file: !1, line: 12, type: !22)
!24 = !DILocation(line: 12, column: 19, scope: !19)
!25 = !DILocalVariable(name: "p", scope: !19, file: !1, line: 14, type: !4)
!26 = !DILocation(line: 14, column: 11, scope: !19)
!27 = !DILocation(line: 14, column: 23, scope: !19)
!28 = !DILocation(line: 14, column: 15, scope: !19)
!29 = !DILocation(line: 15, column: 10, scope: !30)
!30 = distinct !DILexicalBlock(scope: !19, file: !1, line: 15, column: 9)
!31 = !DILocation(line: 15, column: 9, scope: !19)
!32 = !DILocation(line: 16, column: 17, scope: !33)
!33 = distinct !DILexicalBlock(scope: !30, file: !1, line: 15, column: 13)
!34 = !DILocation(line: 16, column: 9, scope: !33)
!35 = !DILocation(line: 17, column: 9, scope: !33)
!36 = !DILocation(line: 19, column: 5, scope: !19)
!37 = !DILocation(line: 19, column: 8, scope: !19)
!38 = !DILocation(line: 19, column: 10, scope: !19)
!39 = !DILocation(line: 20, column: 15, scope: !19)
!40 = !DILocation(line: 20, column: 18, scope: !19)
!41 = !DILocation(line: 20, column: 23, scope: !19)
!42 = !DILocation(line: 20, column: 5, scope: !19)
!43 = !DILocation(line: 20, column: 8, scope: !19)
!44 = !DILocation(line: 20, column: 13, scope: !19)
!45 = !DILocation(line: 21, column: 9, scope: !46)
!46 = distinct !DILexicalBlock(scope: !19, file: !1, line: 21, column: 9)
!47 = !DILocation(line: 21, column: 11, scope: !46)
!48 = !DILocation(line: 21, column: 9, scope: !19)
!49 = !DILocalVariable(name: "cur", scope: !50, file: !1, line: 23, type: !4)
!50 = distinct !DILexicalBlock(scope: !46, file: !1, line: 22, column: 5)
!51 = !DILocation(line: 23, column: 15, scope: !50)
!52 = !DILocation(line: 23, column: 29, scope: !50)
!53 = !DILocation(line: 23, column: 21, scope: !50)
!54 = !DILocation(line: 24, column: 14, scope: !55)
!55 = distinct !DILexicalBlock(scope: !50, file: !1, line: 24, column: 13)
!56 = !DILocation(line: 24, column: 13, scope: !50)
!57 = !DILocation(line: 25, column: 21, scope: !58)
!58 = distinct !DILexicalBlock(scope: !55, file: !1, line: 24, column: 19)
!59 = !DILocation(line: 25, column: 13, scope: !58)
!60 = !DILocation(line: 26, column: 18, scope: !58)
!61 = !DILocation(line: 26, column: 13, scope: !58)
!62 = !DILocation(line: 27, column: 13, scope: !58)
!63 = !DILocation(line: 29, column: 33, scope: !50)
!64 = !DILocation(line: 29, column: 21, scope: !50)
!65 = !DILocation(line: 29, column: 26, scope: !50)
!66 = !DILocation(line: 29, column: 31, scope: !50)
!67 = !DILocation(line: 29, column: 9, scope: !50)
!68 = !DILocation(line: 29, column: 14, scope: !50)
!69 = !DILocation(line: 29, column: 19, scope: !50)
!70 = !DILocation(line: 30, column: 19, scope: !50)
!71 = !DILocation(line: 30, column: 9, scope: !50)
!72 = !DILocation(line: 30, column: 12, scope: !50)
!73 = !DILocation(line: 30, column: 17, scope: !50)
!74 = !DILocation(line: 31, column: 5, scope: !50)
!75 = !DILocation(line: 33, column: 10, scope: !19)
!76 = !DILocation(line: 33, column: 5, scope: !19)
!77 = !DILocation(line: 34, column: 5, scope: !19)
!78 = !DILocation(line: 35, column: 1, scope: !19)
!79 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 37, type: !80, scopeLine: 38, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !2)
!80 = !DISubroutineType(types: !81)
!81 = !{!22}
!82 = !DILocalVariable(name: "x", scope: !79, file: !1, line: 39, type: !22)
!83 = !DILocation(line: 39, column: 9, scope: !79)
!84 = !DILocalVariable(name: "ret", scope: !79, file: !1, line: 40, type: !22)
!85 = !DILocation(line: 40, column: 9, scope: !79)
!86 = !DILocation(line: 41, column: 5, scope: !79)
!87 = !DILocation(line: 42, column: 21, scope: !79)
!88 = !DILocation(line: 42, column: 11, scope: !79)
!89 = !DILocation(line: 42, column: 9, scope: !79)
!90 = !DILocation(line: 43, column: 8, scope: !91)
!91 = distinct !DILexicalBlock(scope: !79, file: !1, line: 43, column: 8)
!92 = !DILocation(line: 43, column: 12, scope: !91)
!93 = !DILocation(line: 43, column: 8, scope: !79)
!94 = !DILocation(line: 44, column: 9, scope: !95)
!95 = distinct !DILexicalBlock(scope: !91, file: !1, line: 43, column: 18)
!96 = !DILocation(line: 46, column: 5, scope: !79)
!97 = !DILocation(line: 47, column: 1, scope: !79)
