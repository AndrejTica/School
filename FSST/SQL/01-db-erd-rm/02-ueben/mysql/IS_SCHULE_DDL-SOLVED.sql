SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL';

DROP SCHEMA IF EXISTS `is_schule` ;
CREATE SCHEMA IF NOT EXISTS `is_schule` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci ;
USE `is_schule` ;

-- -----------------------------------------------------
-- Table `is_schule`.`Schule`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Schule` (
  `schulkennzahl` VARCHAR(10) NOT NULL ,
  `name` VARCHAR(45) NOT NULL ,
  `adresse` VARCHAR(45) NULL ,
  PRIMARY KEY (`schulkennzahl`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `is_schule`.`Abteilungen`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Abteilungen` (
  `idAbteilungen` INT NOT NULL AUTO_INCREMENT ,
  `name` VARCHAR(45) NOT NULL ,
  `Schule_schulkennzahl` VARCHAR(10) NOT NULL ,
  PRIMARY KEY (`idAbteilungen`) ,
  INDEX `fk_Abteilungen_Schule1` (`Schule_schulkennzahl` ASC) ,
  CONSTRAINT `fk_Abteilungen_Schule1`
    FOREIGN KEY (`Schule_schulkennzahl` )
    REFERENCES `is_schule`.`Schule` (`schulkennzahl` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `is_schule`.`Schueler`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Schueler` (
  `katalognr` INT NOT NULL AUTO_INCREMENT ,
  `name` VARCHAR(45) NOT NULL ,
  `email` VARCHAR(45) NULL DEFAULT 'n/a' ,
  `jahrgang` VARCHAR(6) NOT NULL ,
  `Abteilungen_idAbteilungen` INT NOT NULL ,
  PRIMARY KEY (`katalognr`, `jahrgang`) ,
  INDEX `fk_Schueler_Abteilungen` (`Abteilungen_idAbteilungen` ASC) ,
  CONSTRAINT `fk_Schueler_Abteilungen`
    FOREIGN KEY (`Abteilungen_idAbteilungen` )
    REFERENCES `is_schule`.`Abteilungen` (`idAbteilungen` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `is_schule`.`Lehrer`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Lehrer` (
  `idLehrer` INT NOT NULL AUTO_INCREMENT ,
  `name` VARCHAR(45) NOT NULL ,
  PRIMARY KEY (`idLehrer`) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `is_schule`.`Lehrer_has_Abteilungen`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Lehrer_has_Abteilungen` (
  `Lehrer_idLehrer` INT NOT NULL ,
  `Abteilungen_idAbteilungen` INT NOT NULL ,
  PRIMARY KEY (`Lehrer_idLehrer`, `Abteilungen_idAbteilungen`) ,
  INDEX `fk_Lehrer_has_Abteilungen_Abteilungen1` (`Abteilungen_idAbteilungen` ASC) ,
  INDEX `fk_Lehrer_has_Abteilungen_Lehrer1` (`Lehrer_idLehrer` ASC) ,
  CONSTRAINT `fk_Lehrer_has_Abteilungen_Lehrer1`
    FOREIGN KEY (`Lehrer_idLehrer` )
    REFERENCES `is_schule`.`Lehrer` (`idLehrer` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Lehrer_has_Abteilungen_Abteilungen1`
    FOREIGN KEY (`Abteilungen_idAbteilungen` )
    REFERENCES `is_schule`.`Abteilungen` (`idAbteilungen` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `is_schule`.`Lehrer_has_Schueler`
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS `is_schule`.`Lehrer_has_Schueler` (
  `Lehrer_idLehrer` INT NOT NULL ,
  `Schueler_katalognr` INT NOT NULL ,
  `Schueler_jahrgang` VARCHAR(6) NOT NULL ,
  PRIMARY KEY (`Lehrer_idLehrer`, `Schueler_katalognr`, `Schueler_jahrgang`) ,
  INDEX `fk_Lehrer_has_Schueler_Schueler1` (`Schueler_katalognr` ASC, `Schueler_jahrgang` ASC) ,
  INDEX `fk_Lehrer_has_Schueler_Lehrer1` (`Lehrer_idLehrer` ASC) ,
  CONSTRAINT `fk_Lehrer_has_Schueler_Lehrer1`
    FOREIGN KEY (`Lehrer_idLehrer` )
    REFERENCES `is_schule`.`Lehrer` (`idLehrer` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Lehrer_has_Schueler_Schueler1`
    FOREIGN KEY (`Schueler_katalognr` , `Schueler_jahrgang` )
    REFERENCES `is_schule`.`Schueler` (`katalognr` , `jahrgang` )
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;



SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
