-- 상위 n개 레코드 (출력 튜플 갯수 제한: limit)
SELECT distinct NAME from ANIMAL_INS
order by DATETIME
limit 1 

-- 여러 기준 정렬하기
SELECT ANIMAL_ID, NAME, DATETIME FROM ANIMAL_INS
ORDER BY NAME, DATETIME DESC

-- 최댓/최솟값
SELECT max(DATETIME) from ANIMAL_INS
SELECT min(DATETIME) from ANIMAL_INS
-- 동물 수 구하기 
SELECT count(ANIMAL_ID) from ANIMAL_INS

-- 중복 제거한 후의 수 
SELECT count(distinct(NAME)) from ANIMAL_INS
