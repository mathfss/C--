DROP DATABASE IF EXISTS lista5;
CREATE DATABASE lista5;
USE lista5;

CREATE TABLE aluno(
	id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome VARCHAR(50),
    idade INT,
    curso VARCHAR(45),
    email VARCHAR(100)
    );
    
DELIMITER $$
CREATE FUNCTION gerar_email(nome_aluno VARCHAR(50)) RETURNS VARCHAR(100)
DETERMINISTIC
BEGIN
    RETURN CONCAT(nome_aluno, '@exemplo.com');
END$$
DELIMITER ;


DELIMITER $$
CREATE PROCEDURE inserir_aluno(
    IN nome_aluno VARCHAR(50),
    IN idade_aluno INT,
    IN curso_aluno VARCHAR(45)
)
BEGIN
    DECLARE email_aluno VARCHAR(100);
    SET email_aluno = gerar_email(nome_aluno);
    INSERT INTO aluno (nome, idade, curso, email) VALUES (nome_aluno, idade_aluno, curso_aluno, email_aluno);
END$$
DELIMITER ;

CALL inserir_aluno('João', 20, 'Engenharia');
CALL inserir_aluno('Maria', 20, 'Ciência da Computação');
CALL inserir_aluno('Carlos', 16, 'Medicina');
CALL inserir_aluno('Pedro', 17, 'Direito');

DELIMITER $$
CREATE TRIGGER atualizar_idade_aluno
AFTER INSERT ON aluno
FOR EACH ROW
BEGIN
    UPDATE aluno
    SET idade = 20
    WHERE idade = (SELECT MAX(idade) FROM aluno);
END$$
DELIMITER ;

CREATE VIEW alunos_maior_18 AS
SELECT *
FROM aluno
WHERE idade > 18;

SELECT * FROM aluno;

SELECT nome, gerar_email(nome) AS email FROM aluno;

SELECT * FROM alunos_maior_18;
