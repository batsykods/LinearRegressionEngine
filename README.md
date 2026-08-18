                         ┌──────────────────┐
                         │   CSV Dataset    │
                         └────────┬─────────┘
                                  │
                                  ▼
                         ┌──────────────────┐
                         │ Dataset Loader   │
                         └────────┬─────────┘
                                  │
                                  ▼
                         ┌──────────────────┐
                         │ Normalization    │
                         │ mean / std       │
                         └────────┬─────────┘
                                  │
                                  ▼
                         ┌──────────────────┐
                         │ LinearRegression │
                         │ Gradient Descent │
                         └────────┬─────────┘
                                  │
                    ┌─────────────┴─────────────┐
                    ▼                           ▼
             ┌─────────────┐             ┌──────────────┐
             │  Metrics    │             │  Model I/O   │
             │ MSE/RMSE/R² │             │ Save / Load  │
             └─────────────┘             └──────────────┘


             # Linear Regression Engine

A from-scratch machine learning regression engine written in modern C++17,
implementing batch gradient descent, feature standardisation, model
persistence, matrix operations, and regression evaluation metrics.

[Architecture] [Build] [Results] [Technical Details]

## Overview

What the project does and why it exists.

## Architecture

Dataset → Preprocessing → Training → Evaluation → Model Persistence
                         ↓
                  Linear Regression
                  Gradient Descent

## Features

- Batch Gradient Descent
- Z-score Feature Normalisation
- Matrix Operations
- CSV Dataset Loading
- MSE / RMSE / MAE / R²
- Model Save/Load
- CMake Build System
- GitHub Actions CI

## Mathematical Foundation

ŷ = Xw + b

J(w,b) = 1/(2m) Σ(ŷᵢ-yᵢ)²

w := w - α ∂J/∂w
b := b - α ∂J/∂b

## Project Structure

...

## Build

...

## Usage

...

## Results

...

## Validation

Comparison with scikit-learn.

## Engineering Decisions

...

## Limitations

...

## Future Improvements

...
