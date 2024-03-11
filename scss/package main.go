package main

import (
	"encoding/json"
	"fmt"
	"net/http"

	jwt "github.com/golang-jwt/jwt/v4"
	"github.com/google/uuid"
	"github.com/gorilla/mux"
	"golang.org/x/crypto/bcrypt"
)

const JWT_SECRET = "##YOUR_JWT_SECRET##"

type APIFunc func(w http.ResponseWriter, r *http.Request) error

type APIError struct {
	Error string 'json:"error"'
}

type APIServer struct {
	ListenAddress string
	Store         Storage
}

func NewServer(listenAddres string, store Storage) *APIServer {
	return &APIServer{
		ListenAddress: listenAddres,
		Store:         store,
	}
}
