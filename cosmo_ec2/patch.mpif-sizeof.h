--- mpif-sizeof.h.orig	2020-03-21 10:53:11.838365975 +0100
+++ mpif-sizeof.h	2020-03-21 01:16:52.968097449 +0100
@@ -62,62 +62,6 @@
         INTEGER, INTENT(OUT) :: ierror
       END SUBROUTINE MPI_Sizeof_character_r7
 
-      SUBROUTINE MPI_Sizeof_complex128_scalar(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_scalar
-
-      SUBROUTINE MPI_Sizeof_complex128_r1(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r1
-
-      SUBROUTINE MPI_Sizeof_complex128_r2(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r2
-
-      SUBROUTINE MPI_Sizeof_complex128_r3(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r3
-
-      SUBROUTINE MPI_Sizeof_complex128_r4(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r4
-
-      SUBROUTINE MPI_Sizeof_complex128_r5(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r5
-
-      SUBROUTINE MPI_Sizeof_complex128_r6(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r6
-
-      SUBROUTINE MPI_Sizeof_complex128_r7(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_complex128_r7
-
       SUBROUTINE MPI_Sizeof_complex32_scalar(x, size, ierror)
         USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
       COMPLEX(REAL32)::x
@@ -502,62 +446,6 @@
         INTEGER, INTENT(OUT) :: ierror
       END SUBROUTINE MPI_Sizeof_logical_r7
 
-      SUBROUTINE MPI_Sizeof_real128_scalar(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_scalar
-
-      SUBROUTINE MPI_Sizeof_real128_r1(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r1
-
-      SUBROUTINE MPI_Sizeof_real128_r2(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r2
-
-      SUBROUTINE MPI_Sizeof_real128_r3(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r3
-
-      SUBROUTINE MPI_Sizeof_real128_r4(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r4
-
-      SUBROUTINE MPI_Sizeof_real128_r5(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r5
-
-      SUBROUTINE MPI_Sizeof_real128_r6(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r6
-
-      SUBROUTINE MPI_Sizeof_real128_r7(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE MPI_Sizeof_real128_r7
-
       SUBROUTINE MPI_Sizeof_real32_scalar(x, size, ierror)
         USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
       REAL(REAL32)::x
@@ -722,62 +610,6 @@
         INTEGER, INTENT(OUT) :: ierror
       END SUBROUTINE PMPI_Sizeof_character_r7
 
-      SUBROUTINE PMPI_Sizeof_complex128_scalar(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_scalar
-
-      SUBROUTINE PMPI_Sizeof_complex128_r1(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r1
-
-      SUBROUTINE PMPI_Sizeof_complex128_r2(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r2
-
-      SUBROUTINE PMPI_Sizeof_complex128_r3(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r3
-
-      SUBROUTINE PMPI_Sizeof_complex128_r4(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r4
-
-      SUBROUTINE PMPI_Sizeof_complex128_r5(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r5
-
-      SUBROUTINE PMPI_Sizeof_complex128_r6(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r6
-
-      SUBROUTINE PMPI_Sizeof_complex128_r7(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      COMPLEX(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_complex128_r7
-
       SUBROUTINE PMPI_Sizeof_complex32_scalar(x, size, ierror)
         USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
       COMPLEX(REAL32)::x
@@ -1162,62 +994,6 @@
         INTEGER, INTENT(OUT) :: ierror
       END SUBROUTINE PMPI_Sizeof_logical_r7
 
-      SUBROUTINE PMPI_Sizeof_real128_scalar(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_scalar
-
-      SUBROUTINE PMPI_Sizeof_real128_r1(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r1
-
-      SUBROUTINE PMPI_Sizeof_real128_r2(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r2
-
-      SUBROUTINE PMPI_Sizeof_real128_r3(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r3
-
-      SUBROUTINE PMPI_Sizeof_real128_r4(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r4
-
-      SUBROUTINE PMPI_Sizeof_real128_r5(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r5
-
-      SUBROUTINE PMPI_Sizeof_real128_r6(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r6
-
-      SUBROUTINE PMPI_Sizeof_real128_r7(x, size, ierror)
-        USE, INTRINSIC :: iso_fortran_env, ONLY: REAL128
-      REAL(REAL128), DIMENSION(1,1,1,1,1,1,*)::x
-        INTEGER, INTENT(OUT) :: size
-        INTEGER, INTENT(OUT) :: ierror
-      END SUBROUTINE PMPI_Sizeof_real128_r7
-
       SUBROUTINE PMPI_Sizeof_real32_scalar(x, size, ierror)
         USE, INTRINSIC :: iso_fortran_env, ONLY: REAL32
       REAL(REAL32)::x
